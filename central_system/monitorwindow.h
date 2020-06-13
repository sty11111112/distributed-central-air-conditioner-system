#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

#include <QDialog>

namespace Ui {
class monitorWindow;
}

class monitorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit monitorWindow(QWidget *parent = nullptr);
    ~monitorWindow();

private slots:
    void on_monitorFreq_valueChanged(double arg1);//频率改变按钮响应


private:
    Ui::monitorWindow *ui;
    void setRow(int row);//设置tableWidget行数
    void updateTable(int row,int id,int currentTemp,int targetTemp,int wind,double energy,double cost);//按行输入
};

#endif // MONITORWINDOW_H
