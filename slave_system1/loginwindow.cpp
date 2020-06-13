#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#pragma execution_character_set("utf-8")

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("登陆界面");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_registerButton_clicked()
{
    //用户注册判断
    if(ui->usernameLineEdit->text().isEmpty()||ui->pwdLineEdit->text().isEmpty()||ui->usernameLineEdit->text()=="123")
        {
            if(ui->usernameLineEdit->text().isEmpty()||ui->pwdLineEdit->text().isEmpty())
            {
                QMessageBox::warning(this,"警告!","用户名或密码不能为空!",QMessageBox::Yes);
                ui->usernameLineEdit->clear();
                ui->pwdLineEdit->clear();
            }
            else
            {
                QMessageBox::warning(this,"警告!","用户名已存在!",QMessageBox::Yes);
                ui->usernameLineEdit->clear();
                ui->pwdLineEdit->clear();
            }
        }
        else
        {
            accept();
        }
}




void LoginWindow::on_loginButton_clicked()
{
    //用户登陆判断
    if(ui->usernameLineEdit->text()=="123"&&ui->pwdLineEdit->text()=="123")
        {
           accept();
        }
        else
        {
            QMessageBox::warning(this,"警告!","用户名或密码错误!",QMessageBox::Yes);
            ui->usernameLineEdit->clear();
            ui->pwdLineEdit->clear();
        }
}
