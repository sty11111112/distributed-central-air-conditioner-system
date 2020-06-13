#include "mainwindow.h"
#include "loginwindow.h"
#include "SubMachine.h"

#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>

#pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *main=new MainWindow();
    main->setWindowTitle("从控机操作系统");
    bool ok=false;
    int roomid;
    roomid=QInputDialog::getInt(0,"从控机操作系统","房间号",0,1,9,1,&ok);

    if(ok==false)
    {
        QMessageBox::warning(0,"错误","未指定房间号，无法正常开机！",QMessageBox::Ok);
        return 0;
    }
    else
    {
        main->setRoomID(roomid);
        LoginWindow login;
        if(login.exec()==QDialog::Accepted)
        {
            main->show();
            return a.exec();
        }
        else return 0;
    }
}
