#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QButtonGroup>
#include <ctime>
#include <Qtimer>
#include <QMessageBox>
#include "SubMachine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setRoomID(int id);//设定房间编号
    void changePower();//电源设置
	void openFailed();//开机失败
    void openMachine(bool workMode);//开机设置
    void closeMachine();//关机设置
    void increaseTargetTemp();//提高目标温度
	void decreaseTargetTemp();//降低目标温度
	
public slots:


private:
    Ui::MainWindow *ui;
	SubMachine w;
    bool isOpen;//开关状态 0关机 1开机
    bool mode;//工作模式 0制冷 1制暖
    int roomid;//房间序号
    int currentTemp;//当前温度
    int targetTemp;//目标温度
    int windSpeed;//风速模式，0低风 1中风 2高风
    double usedFee;//支付金额
    double usedEnergy;//消耗能量
	int flag;//断连信息是否输出
    void changeCurrentTempShow(int curentTemp);//同步当前温度显示
    void changeWindSpeed(int newWindSpeed);//风速设置
	void updatefees(double fees);
	void changeMode(int inMode);
	
	QTimer *timer;

private slots:


    void on_lowWindButton_clicked();//低风速按钮响应
    void on_middleWindButton_clicked();//中风速按钮响应
    void on_highWindButton_clicked();//高风速按钮响应
    void on_power_clicked();//电源按钮响应
    void on_increaseTemp_clicked();//提高目标温度按钮响应
    void on_decreaseTemp_clicked();//降低目标温度按钮响应
	void do_Sub();
};
#endif // MAINWINDOW_H
