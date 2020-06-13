#include "monitorwindow.h"
#include "ui_monitorwindow.h"
#pragma execution_character_set("utf-8")

monitorWindow::monitorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::monitorWindow)
{
    ui->setupUi(this);
    setWindowTitle("从控机运行情况");
    //测试用例
    setRow(1);
    updateTable(0,1,20,20,0,10.0,20.0);
}

monitorWindow::~monitorWindow()
{
    delete ui;
}

void monitorWindow::on_monitorFreq_valueChanged(double arg1)
{

}
void monitorWindow::setRow(int row)
{
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(6);
}

void monitorWindow::updateTable(int row,int id,int currentTemp,int targetTemp,int wind,double energy,double cost)
{
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString("%1").arg(id)));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString("%1").arg(currentTemp)));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString("%1").arg(targetTemp)));
    if(wind==0)
    {
        ui->tableWidget->setItem(row,3,new QTableWidgetItem("低风"));
    }
    else if(wind==1)
    {
        ui->tableWidget->setItem(row,3,new QTableWidgetItem("中风"));
    }
    else if(wind==2)
    {
        ui->tableWidget->setItem(row,3,new QTableWidgetItem("高风"));
    }
    else
    {
         ui->tableWidget->setItem(row,3,new QTableWidgetItem("--"));
    }
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString::number(energy,'f',1)));

    ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(cost,'f',1)));
}
