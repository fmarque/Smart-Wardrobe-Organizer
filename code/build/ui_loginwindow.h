/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QPushButton *signup_button;
    QPushButton *login_button;
    QLabel *dividerLabel;
    QLabel *pageLabel;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(1024, 768);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        signup_button = new QPushButton(centralwidget);
        signup_button->setObjectName("signup_button");
        signup_button->setGeometry(QRect(390, 560, 241, 31));
        QFont font;
        font.setPointSize(11);
        signup_button->setFont(font);
        login_button = new QPushButton(centralwidget);
        login_button->setObjectName("login_button");
        login_button->setGeometry(QRect(430, 490, 161, 31));
        login_button->setFont(font);
        dividerLabel = new QLabel(centralwidget);
        dividerLabel->setObjectName("dividerLabel");
        dividerLabel->setGeometry(QRect(270, 530, 511, 16));
        pageLabel = new QLabel(centralwidget);
        pageLabel->setObjectName("pageLabel");
        pageLabel->setGeometry(QRect(280, 200, 491, 61));
        QFont font1;
        font1.setPointSize(40);
        pageLabel->setFont(font1);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(270, 260, 481, 211));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(20, 150, 441, 51));
        QFont font2;
        font2.setPointSize(15);
        lineEdit_2->setFont(font2);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 181, 16));
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 130, 181, 16));
        label_2->setFont(font);
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 50, 441, 51));
        lineEdit_3->setFont(font2);
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1024, 21));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        signup_button->setText(QCoreApplication::translate("LoginWindow", "Don't have an account? Sign up", nullptr));
        login_button->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        dividerLabel->setText(QCoreApplication::translate("LoginWindow", "---------------------------------------------- or ----------------------------------------------", nullptr));
        pageLabel->setText(QCoreApplication::translate("LoginWindow", "{Name of App here}", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("LoginWindow", "Enter Username", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Enter Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
