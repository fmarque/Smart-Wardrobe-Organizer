/********************************************************************************
** Form generated from reading UI file 'closetwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSETWINDOW_H
#define UI_CLOSETWINDOW_H

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

class Ui_ClosetWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Arrow1;
    QPushButton *Arrow2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Arrow3;
    QPushButton *Arrow4;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Arrow5;
    QPushButton *Arrow6;
    QSpacerItem *verticalSpacer;
    QPushButton *Arrow7;
    QPushButton *Arrow8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *uploadButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClosetWindow)
    {
        if (ClosetWindow->objectName().isEmpty())
            ClosetWindow->setObjectName("ClosetWindow");
        ClosetWindow->resize(1024, 768);
        ClosetWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 209, 220);"));
        centralwidget = new QWidget(ClosetWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(170, 160, 51, 511));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Arrow1 = new QPushButton(verticalLayoutWidget);
        Arrow1->setObjectName("Arrow1");
        Arrow1->setMinimumSize(QSize(30, 30));
        Arrow1->setMaximumSize(QSize(40, 40));

        verticalLayout->addWidget(Arrow1);

        Arrow2 = new QPushButton(verticalLayoutWidget);
        Arrow2->setObjectName("Arrow2");
        Arrow2->setMinimumSize(QSize(40, 40));
        Arrow2->setMaximumSize(QSize(40, 40));

        verticalLayout->addWidget(Arrow2);

        verticalSpacer_2 = new QSpacerItem(20, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        Arrow3 = new QPushButton(verticalLayoutWidget);
        Arrow3->setObjectName("Arrow3");
        Arrow3->setMinimumSize(QSize(40, 40));
        Arrow3->setMaximumSize(QSize(40, 40));

        verticalLayout->addWidget(Arrow3);

        Arrow4 = new QPushButton(verticalLayoutWidget);
        Arrow4->setObjectName("Arrow4");
        Arrow4->setMinimumSize(QSize(40, 40));
        Arrow4->setMaximumSize(QSize(40, 40));

        verticalLayout->addWidget(Arrow4);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(810, 160, 51, 511));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Arrow5 = new QPushButton(verticalLayoutWidget_2);
        Arrow5->setObjectName("Arrow5");
        Arrow5->setMinimumSize(QSize(40, 40));
        Arrow5->setMaximumSize(QSize(40, 40));

        verticalLayout_2->addWidget(Arrow5);

        Arrow6 = new QPushButton(verticalLayoutWidget_2);
        Arrow6->setObjectName("Arrow6");
        Arrow6->setMinimumSize(QSize(40, 40));
        Arrow6->setMaximumSize(QSize(40, 40));

        verticalLayout_2->addWidget(Arrow6);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        Arrow7 = new QPushButton(verticalLayoutWidget_2);
        Arrow7->setObjectName("Arrow7");
        Arrow7->setMinimumSize(QSize(40, 40));
        Arrow7->setMaximumSize(QSize(40, 40));

        verticalLayout_2->addWidget(Arrow7);

        Arrow8 = new QPushButton(verticalLayoutWidget_2);
        Arrow8->setObjectName("Arrow8");
        Arrow8->setMinimumSize(QSize(40, 40));
        Arrow8->setMaximumSize(QSize(40, 40));

        verticalLayout_2->addWidget(Arrow8);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(220, 669, 591, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveButton = new QPushButton(horizontalLayoutWidget);
        saveButton->setObjectName("saveButton");

        horizontalLayout->addWidget(saveButton);

        loadButton = new QPushButton(horizontalLayoutWidget);
        loadButton->setObjectName("loadButton");

        horizontalLayout->addWidget(loadButton);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(70, 100, 901, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        uploadButton = new QPushButton(horizontalLayoutWidget_2);
        uploadButton->setObjectName("uploadButton");

        horizontalLayout_2->addWidget(uploadButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_2->addWidget(pushButton_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 580, 100, 95));
        label_4->setMinimumSize(QSize(100, 95));
        label_4->setMaximumSize(QSize(100, 95));
        label_4->setAutoFillBackground(false);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 33, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 200, 160, 170));
        label_2->setMinimumSize(QSize(160, 170));
        label_2->setMaximumSize(QSize(160, 170));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 29, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 380, 140, 190));
        label_3->setMinimumSize(QSize(140, 190));
        label_3->setMaximumSize(QSize(140, 190));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 34, 255);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(340, 160, 160, 170));
        label_5->setMinimumSize(QSize(160, 170));
        label_5->setMaximumSize(QSize(160, 170));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 29, 0);"));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, -10, 1031, 136));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setMinimumSize(QSize(370, 110));
        label->setMaximumSize(QSize(370, 110));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/My-Closet-11-13-2024 (1).png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label);

        ClosetWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClosetWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1024, 24));
        ClosetWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClosetWindow);
        statusbar->setObjectName("statusbar");
        ClosetWindow->setStatusBar(statusbar);

        retranslateUi(ClosetWindow);

        QMetaObject::connectSlotsByName(ClosetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClosetWindow)
    {
        ClosetWindow->setWindowTitle(QCoreApplication::translate("ClosetWindow", "MainWindow", nullptr));
        Arrow1->setText(QCoreApplication::translate("ClosetWindow", "<", nullptr));
        Arrow2->setText(QCoreApplication::translate("ClosetWindow", "<", nullptr));
        Arrow3->setText(QCoreApplication::translate("ClosetWindow", "<", nullptr));
        Arrow4->setText(QCoreApplication::translate("ClosetWindow", "<", nullptr));
        Arrow5->setText(QCoreApplication::translate("ClosetWindow", ">", nullptr));
        Arrow6->setText(QCoreApplication::translate("ClosetWindow", ">", nullptr));
        Arrow7->setText(QCoreApplication::translate("ClosetWindow", ">", nullptr));
        Arrow8->setText(QCoreApplication::translate("ClosetWindow", ">", nullptr));
        saveButton->setText(QCoreApplication::translate("ClosetWindow", "Save Outfit", nullptr));
        loadButton->setText(QCoreApplication::translate("ClosetWindow", "Load Outfit", nullptr));
        uploadButton->setText(QCoreApplication::translate("ClosetWindow", "Upload Clothing Item", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ClosetWindow", "View Saved Outfits", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ClosetWindow", "View Clothing Iterms", nullptr));
        label_4->setText(QCoreApplication::translate("ClosetWindow", "Shoes", nullptr));
        label_2->setText(QCoreApplication::translate("ClosetWindow", "Tops", nullptr));
        label_3->setText(QCoreApplication::translate("ClosetWindow", "Bottoms", nullptr));
        label_5->setText(QCoreApplication::translate("ClosetWindow", "Overwear", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClosetWindow: public Ui_ClosetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSETWINDOW_H
