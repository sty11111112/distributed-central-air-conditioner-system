#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "monitorwindow.h"
#include "reportwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_power_clicked();//电源按钮响应

    void on_increaseTargetTemp_clicked();//提高缺省温度按钮响应

    void on_decreaseTargetTemp_clicked();//降低缺省温度按钮响应

    void on_setColdMode_clicked();//制冷模式按钮响应

    void on_setWarmMode_clicked();//供暖模式按钮响应

    void on_monitorButton_clicked();//实时监控按钮响应


    void on_reportButton_clicked();//报表查询按钮响应

private:
    Ui::MainWindow *ui;
    bool isOpen;//开关状态 0关机 1开机
    bool mode;//工作模式 0制冷 1制暖
    int targetTemp;//目标温度
    monitorWindow *mw;
    reportWindow *rw;
    void openMachine();//开机设置
    void closeMachine();//关节设置
    void showMode();//模式显示
    void showTargetTemp();//目标温度显示

};
#endif // MAINWINDOW_H
