#include "reportwindow.h"
#include "ui_reportwindow.h"

reportWindow::reportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportWindow)
{
    ui->setupUi(this);
}

reportWindow::~reportWindow()
{
    delete ui;
}


void reportWindow::on_refreshButton_clicked()
{

}

void reportWindow::on_cleanupButton_clicked()
{

}
void reportWindow::setRow(int row)
{
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(10);
}
void reportWindow::updateTable(int row,int id, int times, QDateTime startTime, QDateTime endTime, int startTmp, int endTmp, int wind, double energy, double cost, double totalCost)
{
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString("%1").arg(id)));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString("%1").arg(times)));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(startTime.toString("yyyy-MM-dd hh:mm:ss")));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(endTime.toString("yyyy-MM-dd hh:mm:ss")));
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString("%1").arg(startTmp)));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString("%1").arg(endTmp)));
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
    ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(totalCost,'f',1)));

}




void reportWindow::on_dayButton_clicked()
{
    reportMode=0;
    ui->stackedWidget->setCurrentIndex(0);
}

void reportWindow::on_weekButton_clicked()
{
    reportMode=1;
    ui->stackedWidget->setCurrentIndex(1);
}

void reportWindow::on_monthButton_clicked()
{
    reportMode=2;
    ui->stackedWidget->setCurrentIndex(2);
}

void reportWindow::on_dayChoose_userDateChanged(const QDate &date)
{

}

void reportWindow::on_weekChoose_activated(const QString &arg1)
{

}

void reportWindow::on_monthEdit_activated(const QString &arg1)
{

}
