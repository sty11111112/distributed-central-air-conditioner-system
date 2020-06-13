#include "mainwindow.h"
#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isOpen=false;
    mw =new monitorWindow();
    mw->setVisible(false);
    rw =new reportWindow();
    rw->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;


}


void MainWindow::on_power_clicked()
{
    if(isOpen==false)
    {
        openMachine();
    }
    else
    {
        closeMachine();
    }
}

void MainWindow::on_increaseTargetTemp_clicked()
{
    if(mode==false)
    {
        if(targetTemp<25)
        {
            targetTemp++;
            showTargetTemp();
        }
    }
    else
    {
        if(targetTemp<30)
        {
            targetTemp++;
            showTargetTemp();
        }
    }
}

void MainWindow::on_decreaseTargetTemp_clicked()
{
    if(mode==false)
    {
        if(targetTemp>18)
        {
            targetTemp--;
            showTargetTemp();
        }
    }
    else
    {
        if(targetTemp>25)
        {
            targetTemp--;
            showTargetTemp();
        }
    }
}

void MainWindow::on_setColdMode_clicked()
{
    mode=false;
    targetTemp=22;
    showMode();
}

void MainWindow::on_setWarmMode_clicked()
{
    mode=true;
    targetTemp=28;
    showMode();
}

void MainWindow::on_monitorButton_clicked()
{
    mw->setVisible(true);
}

void MainWindow::on_reportButton_clicked()
{
     rw->setVisible(true);
}

void MainWindow::openMachine()
{
    isOpen=true;
    mode=false;
    ui->power->setText("关机");
    ui->setColdMode->setEnabled(true);
    ui->setWarmMode->setEnabled(true);
    ui->increaseTargetTemp->setEnabled(true);
    ui->decreaseTargetTemp->setEnabled(true);
    ui->monitorButton->setEnabled(true);
    ui->reportButton->setEnabled(true);
}
void MainWindow::closeMachine()
{
    isOpen=false;
    ui->power->setText("开机");
    ui->setColdMode->setEnabled(false);
    ui->setWarmMode->setEnabled(false);
    ui->increaseTargetTemp->setEnabled(false);
    ui->decreaseTargetTemp->setEnabled(false);
    ui->monitorButton->setEnabled(false);
    ui->reportButton->setEnabled(false);
}

void MainWindow::showMode()
{
    if(mode==false)
    {
        ui->mode->setText("制冷");
        showTargetTemp();
    }
    else
    {
        ui->mode->setText("供暖");
        showTargetTemp();
    }
}
void MainWindow::showTargetTemp()
{
    ui->targetTemp->setText(QString::number(targetTemp));
}
