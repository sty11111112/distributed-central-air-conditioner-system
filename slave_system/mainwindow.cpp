#include "mainwindow.h"
#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isOpen=false;
    currentTemp=25;

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setRoomID(int id)
{
    roomid=id;
    ui->roomID->setText(QString::number(roomid));
}
void MainWindow::changeWindSpeed(int newWindSpeed)
{
    QString wind;
    windSpeed=newWindSpeed;
    switch (newWindSpeed) {
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
    changeWindSpeed(0);
}

void MainWindow::on_middleWindButton_clicked()
{
    changeWindSpeed(1);
}


void MainWindow::on_highWindButton_clicked()
{
    changeWindSpeed(2);
}

void MainWindow::changePower(){
    if(isOpen==false)
    {
        //判断通信是否成功
        //如果失败
        openMachine(0);

    }
    else
    {
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
            targetTemp++;
            ui->targetTemp->setText(QString::number(targetTemp));
        }
    }
    else
    {
        if(targetTemp<30)
        {
            targetTemp++;
            ui->targetTemp->setText(QString::number(targetTemp));
        }
    }
}
void MainWindow::decreaseTargetTemp()
{
    if(mode==0)
    {
        if(targetTemp>18)
        {
            targetTemp--;
            ui->targetTemp->setText(QString::number(targetTemp));
        }
    }
    else
    {
        if(targetTemp>25)
        {
            targetTemp--;
            ui->targetTemp->setText(QString::number(targetTemp));
        }
    }
}
void MainWindow::changeCurrentTempShow(int curentTemp)
{
    ui->currentTemp->setText(QString::number(currentTemp));
}
