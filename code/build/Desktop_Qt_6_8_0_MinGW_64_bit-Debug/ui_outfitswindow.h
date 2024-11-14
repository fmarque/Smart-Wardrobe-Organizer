/********************************************************************************
** Form generated from reading UI file 'outfitswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTFITSWINDOW_H
#define UI_OUTFITSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutfitsWindow
{
public:
    QWidget *centralwidget;
    QLabel *pageLabel;
    QPushButton *backToMainMenu_button;
    QScrollArea *scrollArea;
    QWidget *outfitsLayout;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_6;
    QPushButton *viewClothingItems_button;
    QPushButton *viewCloset_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OutfitsWindow)
    {
        if (OutfitsWindow->objectName().isEmpty())
            OutfitsWindow->setObjectName("OutfitsWindow");
        OutfitsWindow->resize(1024, 768);
        centralwidget = new QWidget(OutfitsWindow);
        centralwidget->setObjectName("centralwidget");
        pageLabel = new QLabel(centralwidget);
        pageLabel->setObjectName("pageLabel");
        pageLabel->setGeometry(QRect(420, 70, 201, 61));
        QFont font;
        font.setPointSize(25);
        pageLabel->setFont(font);
        backToMainMenu_button = new QPushButton(centralwidget);
        backToMainMenu_button->setObjectName("backToMainMenu_button");
        backToMainMenu_button->setGeometry(QRect(80, 80, 141, 24));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(80, 160, 851, 551));
        scrollArea->setWidgetResizable(true);
        outfitsLayout = new QWidget();
        outfitsLayout->setObjectName("outfitsLayout");
        outfitsLayout->setGeometry(QRect(0, 0, 849, 549));
        groupBox = new QGroupBox(outfitsLayout);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 40, 250, 370));
        groupBox_2 = new QGroupBox(outfitsLayout);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(300, 40, 250, 370));
        groupBox_3 = new QGroupBox(outfitsLayout);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(580, 40, 250, 370));
        groupBox_4 = new QGroupBox(outfitsLayout);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(20, 460, 250, 370));
        groupBox_5 = new QGroupBox(outfitsLayout);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(300, 460, 250, 370));
        groupBox_6 = new QGroupBox(outfitsLayout);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(580, 460, 250, 370));
        scrollArea->setWidget(outfitsLayout);
        viewClothingItems_button = new QPushButton(centralwidget);
        viewClothingItems_button->setObjectName("viewClothingItems_button");
        viewClothingItems_button->setGeometry(QRect(790, 80, 141, 24));
        viewCloset_button = new QPushButton(centralwidget);
        viewCloset_button->setObjectName("viewCloset_button");
        viewCloset_button->setGeometry(QRect(790, 110, 141, 24));
        OutfitsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OutfitsWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1024, 21));
        OutfitsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OutfitsWindow);
        statusbar->setObjectName("statusbar");
        OutfitsWindow->setStatusBar(statusbar);

        retranslateUi(OutfitsWindow);

        QMetaObject::connectSlotsByName(OutfitsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OutfitsWindow)
    {
        OutfitsWindow->setWindowTitle(QCoreApplication::translate("OutfitsWindow", "MainWindow", nullptr));
        pageLabel->setText(QCoreApplication::translate("OutfitsWindow", "Saved Outfits", nullptr));
        backToMainMenu_button->setText(QCoreApplication::translate("OutfitsWindow", "Back to Main Menu", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OutfitsWindow", "{Outfit 1 Name}", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("OutfitsWindow", "{Outfit 2 Name}", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("OutfitsWindow", "{Outfit 3 Name}", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("OutfitsWindow", "{Outfit 4 Name}", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("OutfitsWindow", "{Outfit 5 Name}", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("OutfitsWindow", "{Outfit 6 Name}", nullptr));
        viewClothingItems_button->setText(QCoreApplication::translate("OutfitsWindow", "View Clothing Items", nullptr));
        viewCloset_button->setText(QCoreApplication::translate("OutfitsWindow", "View Closet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutfitsWindow: public Ui_OutfitsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTFITSWINDOW_H
