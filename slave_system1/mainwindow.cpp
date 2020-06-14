#include "mainwindow.h"
#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	qsrand(time(NULL));
	ui->setupUi(this);
	isOpen = false;
	currentTemp = 25;
	w.initial_temp(currentTemp);
	w.set_lastwind(1);
	flag = 0;

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(do_Sub()));
	timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setRoomID(int id)
{
    roomid=id;
    ui->roomID->setText(QString::number(roomid));
	w.set_RoomID(id);
}
void MainWindow::changeWindSpeed(int newWindSpeed)
{
    QString wind;
    windSpeed=newWindSpeed;
    switch (newWindSpeed) {
	case -1:
		wind = "-";
		break;
    case 0:
        wind="低风";
        break;
    case 1:
        wind="中风";
        break;
    case 2:
        wind="高风";
        break;
    default:
        QMessageBox::warning(0,"错误","风速设置出错",QMessageBox::Ok);
        exit(0);
    }
    ui->wind->setText(wind);
}




void MainWindow::on_lowWindButton_clicked()
{
    //changeWindSpeed(0);
	if (w.get_current_wind() == -1)
		w.set_lastwind(0);
	else
		w.changeWindSpeed(0);
}

void MainWindow::on_middleWindButton_clicked()
{
	if (w.get_current_wind() == -1)
		w.set_lastwind(1);
	else
		w.changeWindSpeed(1);
    //changeWindSpeed(1);
}


void MainWindow::on_highWindButton_clicked()
{
    //changeWindSpeed(2);
	if (w.get_current_wind() == -1)
		w.set_lastwind(2);
	else
		w.changeWindSpeed(2);
}

void MainWindow::changePower(){
    if(isOpen==false)
    {
        //判断通信是否成功
        //如果失败
		if (w.OpenMachine() == -1) {
			openFailed();
		}
		else {
			openMachine(0);
		}
    }
    else
    {
		w.CloseMachine();
        closeMachine();
		
    }
}
void MainWindow::openFailed()
{
    QMessageBox::warning(this,"开机失败","无法连接中央空调");
}
void MainWindow::openMachine(bool workMode)
{
    mode=workMode;
    if(mode==false)
    {
        ui->mode->setText("制冷");
    }
    else
    {
        ui->mode->setText("供暖");
    }
    changeCurrentTempShow(currentTemp);
    isOpen=true;
    targetTemp=currentTemp;
    ui->power->setText("关机");
    ui->increaseTemp->setEnabled(true);
    ui->decreaseTemp->setEnabled(true);
    ui->lowWindButton->setEnabled(true);
    ui->middleWindButton->setEnabled(true);
    ui->highWindButton->setEnabled(true);
    changeWindSpeed(1);
    usedEnergy=0;
    ui->energy->setText("0.0");
    usedFee=0;
    ui->cost->setText("0.0");
}

void MainWindow::closeMachine()
{
    isOpen=false;
    ui->increaseTemp->setEnabled(false);
    ui->decreaseTemp->setEnabled(false);
    ui->lowWindButton->setEnabled(false);
    ui->middleWindButton->setEnabled(false);
    ui->highWindButton->setEnabled(false);
    ui->mode->setText("-");
    ui->currentTemp->setText("-");
    ui->targetTemp->setText("-");
    ui->energy->setText("-");
    ui->cost->setText("-");
}

void MainWindow::on_power_clicked()
{
    changePower();
}

void MainWindow::on_increaseTemp_clicked()
{
    increaseTargetTemp();
}

void MainWindow::on_decreaseTemp_clicked()
{
    decreaseTargetTemp();
}
void MainWindow::increaseTargetTemp()
{
    if(mode==0)
    {
        if(targetTemp<25)
        {
            //targetTemp++;
            //ui->targetTemp->setText(QString::number(targetTemp));
			w.increaseTargetTemp();
        }
    }
    else
    {
        if(targetTemp<30)
        {
            //targetTemp++;
            //ui->targetTemp->setText(QString::number(targetTemp));
			w.increaseTargetTemp();
        }
    }
}
void MainWindow::decreaseTargetTemp()
{
    if(mode==0)
    {
        if(targetTemp>18)
        {
            //targetTemp--;
            //ui->targetTemp->setText(QString::number(targetTemp));
			w.decreaseTargetTemp();
        }
    }
    else
    {
        if(targetTemp>25)
        {
            //targetTemp--;
            //ui->targetTemp->setText(QString::number(targetTemp));
			w.decreaseTargetTemp();
        }
    }
}
void MainWindow::changeCurrentTempShow(int temp)
{
    ui->currentTemp->setText(QString::number(temp));
}

void MainWindow::updatefees(double fees)
{
	usedFee = fees;
	usedEnergy = fees / 5;
	ui->cost->setText(QString::number(usedFee));
	ui->energy->setText(QString::number(usedEnergy));
}

void MainWindow::changeMode(int inMode)
{

	if (inMode == -1){}

	if (inMode == 0)
	{
		mode = 0;
		ui->mode->setText("制冷");
	}
	if (inMode == 1)
	{
		mode = 1;
		ui->mode->setText("供暖");
	}
}

void MainWindow::do_Sub()
{	
	if (w.get_working_state() == 1) {
		w.Start();
		changeCurrentTempShow(w.get_current_temp());
		updatefees(w.get_fee());
		changeMode(w.get_main_working_mode());
		targetTemp = w.get_target_temp();
		ui->targetTemp->setText(QString::number(targetTemp));
		changeWindSpeed(w.get_current_wind());
		/*if (w.get_last_wind() != NULL && w.get_current_wind() == NULL) {
			changeWindSpeed(-1);
		}
		if (windSpeed == -1 && w.get_last_wind() == w.get_current_wind() && w.get_current_wind() != NULL) {
			changeWindSpeed(w.get_current_wind());
		}*/
		if (w.islinked() == -1 && flag == 0) {
			QMessageBox::warning(this, "连接断开", "正在尝试重连");
			flag = 1;
		}
		if (w.islinked() == 1)
			flag = 0;
	}
}