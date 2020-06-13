#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_registerButton_clicked();//注册按钮响应

    void on_loginButton_clicked();//登录按钮响应

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
