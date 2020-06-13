#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDialog>

namespace Ui {
class reportWindow;
}

class reportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit reportWindow(QWidget *parent = nullptr);
    ~reportWindow();

private slots:
    void on_refreshButton_clicked();//更新按钮响应

    void on_cleanupButton_clicked();//重置按钮响应



    void on_dayButton_clicked();//日报表按钮响应

    void on_weekButton_clicked();//周报表按钮响应

    void on_monthButton_clicked();//月报表按钮响应


    void on_dayChoose_userDateChanged(const QDate &date);//选择日期按钮响应

    void on_weekChoose_activated(const QString &arg1);//选择星期按钮响应

    void on_monthEdit_activated(const QString &arg1);//选择月份按钮响应

private:
    Ui::reportWindow *ui;
    int reportMode;//报表模式 0day 1week 2month
    void setRow(int row);//设置tableWidget行数
    void updateTable(int row,int id,int times,QDateTime startTime,QDateTime endTime,int startTmp,int endTmp,int wind,double energy,double cost,double totalCost);//按行输入
};

#endif // REPORTWINDOW_H
