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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *enterInfoLayout;
    QTextEdit *enterUser_textEdit;
    QTextEdit *enterPw_textEdit;
    QPushButton *signup_button;
    QPushButton *login_button;
    QLabel *dividerLabel;
    QLabel *pageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(1024, 768);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(270, 320, 481, 151));
        enterInfoLayout = new QVBoxLayout(verticalLayoutWidget);
        enterInfoLayout->setObjectName("enterInfoLayout");
        enterInfoLayout->setContentsMargins(0, 0, 0, 0);
        enterUser_textEdit = new QTextEdit(verticalLayoutWidget);
        enterUser_textEdit->setObjectName("enterUser_textEdit");

        enterInfoLayout->addWidget(enterUser_textEdit);

        enterPw_textEdit = new QTextEdit(verticalLayoutWidget);
        enterPw_textEdit->setObjectName("enterPw_textEdit");

        enterInfoLayout->addWidget(enterPw_textEdit);

        signup_button = new QPushButton(centralwidget);
        signup_button->setObjectName("signup_button");
        signup_button->setGeometry(QRect(410, 560, 201, 31));
        login_button = new QPushButton(centralwidget);
        login_button->setObjectName("login_button");
        login_button->setGeometry(QRect(430, 490, 161, 31));
        dividerLabel = new QLabel(centralwidget);
        dividerLabel->setObjectName("dividerLabel");
        dividerLabel->setGeometry(QRect(270, 530, 511, 16));
        pageLabel = new QLabel(centralwidget);
        pageLabel->setObjectName("pageLabel");
        pageLabel->setGeometry(QRect(280, 220, 491, 61));
        QFont font;
        font.setPointSize(40);
        pageLabel->setFont(font);
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
        enterUser_textEdit->setHtml(QCoreApplication::translate("LoginWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Enter username</span></p></body></html>", nullptr));
        enterPw_textEdit->setHtml(QCoreApplication::translate("LoginWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Enter password</span></p></body></html>", nullptr));
        signup_button->setText(QCoreApplication::translate("LoginWindow", "Don't have an account? Sign up", nullptr));
        login_button->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        dividerLabel->setText(QCoreApplication::translate("LoginWindow", "---------------------------------------------- or ----------------------------------------------", nullptr));
        pageLabel->setText(QCoreApplication::translate("LoginWindow", "{Name of App here}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
