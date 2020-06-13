/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *roomID;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *power;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLabel *mode;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *currentTemp;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QLabel *targetTemp;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *increaseTemp;
    QPushButton *decreaseTemp;
    QSpacerItem *horizontalSpacer_12;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_21;
    QLabel *wind;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *lowWindButton;
    QPushButton *middleWindButton;
    QPushButton *highWindButton;
    QSpacerItem *horizontalSpacer_16;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_18;
    QLabel *cost;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_19;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_21;
    QLabel *energy;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_22;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(708, 463);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        roomID = new QLabel(widget);
        roomID->setObjectName(QString::fromUtf8("roomID"));

        horizontalLayout->addWidget(roomID);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        power = new QPushButton(widget);
        power->setObjectName(QString::fromUtf8("power"));

        horizontalLayout->addWidget(power);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        mode = new QLabel(widget_2);
        mode->setObjectName(QString::fromUtf8("mode"));

        horizontalLayout_2->addWidget(mode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        currentTemp = new QLabel(widget_2);
        currentTemp->setObjectName(QString::fromUtf8("currentTemp"));

        horizontalLayout_2->addWidget(currentTemp);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        targetTemp = new QLabel(widget_3);
        targetTemp->setObjectName(QString::fromUtf8("targetTemp"));

        horizontalLayout_3->addWidget(targetTemp);

        label_14 = new QLabel(widget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        increaseTemp = new QPushButton(widget_3);
        increaseTemp->setObjectName(QString::fromUtf8("increaseTemp"));
        increaseTemp->setEnabled(false);

        horizontalLayout_3->addWidget(increaseTemp);

        decreaseTemp = new QPushButton(widget_3);
        decreaseTemp->setObjectName(QString::fromUtf8("decreaseTemp"));
        decreaseTemp->setEnabled(false);

        horizontalLayout_3->addWidget(decreaseTemp);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_21 = new QLabel(widget_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_4->addWidget(label_21);

        wind = new QLabel(widget_4);
        wind->setObjectName(QString::fromUtf8("wind"));

        horizontalLayout_4->addWidget(wind);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        label_15 = new QLabel(widget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_4->addWidget(label_15);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        lowWindButton = new QPushButton(widget_4);
        lowWindButton->setObjectName(QString::fromUtf8("lowWindButton"));
        lowWindButton->setEnabled(false);

        horizontalLayout_4->addWidget(lowWindButton);

        middleWindButton = new QPushButton(widget_4);
        middleWindButton->setObjectName(QString::fromUtf8("middleWindButton"));
        middleWindButton->setEnabled(false);

        horizontalLayout_4->addWidget(middleWindButton);

        highWindButton = new QPushButton(widget_4);
        highWindButton->setObjectName(QString::fromUtf8("highWindButton"));
        highWindButton->setEnabled(false);

        horizontalLayout_4->addWidget(highWindButton);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_16);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);

        cost = new QLabel(widget_5);
        cost->setObjectName(QString::fromUtf8("cost"));

        horizontalLayout_5->addWidget(cost);

        label_19 = new QLabel(widget_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_5->addWidget(label_19);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_19);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(centralwidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_16 = new QLabel(widget_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_6->addWidget(label_16);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_21);

        energy = new QLabel(widget_6);
        energy->setObjectName(QString::fromUtf8("energy"));

        horizontalLayout_6->addWidget(energy);

        label_20 = new QLabel(widget_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_6->addWidget(label_20);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_22);


        verticalLayout->addWidget(widget_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 708, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\210\277\351\227\264\347\274\226\345\217\267:", nullptr));
        roomID->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        power->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\272\220", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\250\241\345\274\217\357\274\232", nullptr));
        mode->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\270\251\345\272\246\357\274\232", nullptr));
        currentTemp->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\342\204\203", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\350\256\276\347\275\256\357\274\232", nullptr));
        targetTemp->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\342\204\203", nullptr));
        increaseTemp->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        decreaseTemp->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\243\216\351\200\237\357\274\232", nullptr));
        wind->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\351\243\216\351\200\237\350\256\276\347\275\256\357\274\232", nullptr));
        lowWindButton->setText(QCoreApplication::translate("MainWindow", "\344\275\216\351\243\216", nullptr));
        middleWindButton->setText(QCoreApplication::translate("MainWindow", "\344\270\255\351\243\216", nullptr));
        highWindButton->setText(QCoreApplication::translate("MainWindow", "\351\253\230\351\243\216", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\267\262\347\224\250\350\264\271\347\224\250\357\274\232", nullptr));
        cost->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\345\205\203", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\345\267\262\347\224\250\350\203\275\351\207\217\357\274\232", nullptr));
        energy->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\347\204\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
