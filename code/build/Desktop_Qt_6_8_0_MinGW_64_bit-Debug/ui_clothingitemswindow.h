/********************************************************************************
** Form generated from reading UI file 'clothingitemswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOTHINGITEMSWINDOW_H
#define UI_CLOTHINGITEMSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClothingItemsWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *categoriesLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *clothesLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QFrame *frame_5;
    QFrame *frame_6;
    QFrame *frame_7;
    QFrame *frame_8;
    QFrame *frame_9;
    QFrame *frame_10;
    QFrame *frame_11;
    QFrame *frame_12;
    QLabel *pageLabel;
    QPushButton *viewCloset_button;
    QPushButton *viewClothingItems_button;
    QPushButton *backToMainMeny_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClothingItemsWindow)
    {
        if (ClothingItemsWindow->objectName().isEmpty())
            ClothingItemsWindow->setObjectName("ClothingItemsWindow");
        ClothingItemsWindow->resize(1024, 768);
        centralwidget = new QWidget(ClothingItemsWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 170, 891, 51));
        categoriesLayout = new QHBoxLayout(horizontalLayoutWidget);
        categoriesLayout->setObjectName("categoriesLayout");
        categoriesLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        categoriesLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        categoriesLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        categoriesLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");

        categoriesLayout->addWidget(pushButton);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(70, 210, 891, 511));
        clothesLayout = new QGridLayout(gridLayoutWidget);
        clothesLayout->setObjectName("clothesLayout");
        clothesLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(gridLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 887, 507));
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 30, 170, 170));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(30, 240, 170, 170));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_3 = new QFrame(scrollAreaWidgetContents);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(240, 30, 170, 170));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        frame_4 = new QFrame(scrollAreaWidgetContents);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(460, 30, 170, 170));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        frame_5 = new QFrame(scrollAreaWidgetContents);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(680, 30, 170, 170));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        frame_6 = new QFrame(scrollAreaWidgetContents);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(240, 240, 170, 170));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        frame_7 = new QFrame(scrollAreaWidgetContents);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(460, 240, 170, 170));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        frame_8 = new QFrame(scrollAreaWidgetContents);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(680, 240, 170, 170));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        frame_9 = new QFrame(scrollAreaWidgetContents);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(30, 450, 170, 170));
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        frame_10 = new QFrame(scrollAreaWidgetContents);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(240, 450, 170, 170));
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        frame_11 = new QFrame(scrollAreaWidgetContents);
        frame_11->setObjectName("frame_11");
        frame_11->setGeometry(QRect(460, 450, 170, 170));
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        frame_12 = new QFrame(scrollAreaWidgetContents);
        frame_12->setObjectName("frame_12");
        frame_12->setGeometry(QRect(680, 450, 170, 170));
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        scrollArea->setWidget(scrollAreaWidgetContents);

        clothesLayout->addWidget(scrollArea, 0, 0, 1, 1);

        pageLabel = new QLabel(centralwidget);
        pageLabel->setObjectName("pageLabel");
        pageLabel->setGeometry(QRect(440, 80, 261, 51));
        QFont font;
        font.setPointSize(30);
        pageLabel->setFont(font);
        pageLabel->setLineWidth(1);
        viewCloset_button = new QPushButton(centralwidget);
        viewCloset_button->setObjectName("viewCloset_button");
        viewCloset_button->setGeometry(QRect(820, 110, 141, 24));
        viewClothingItems_button = new QPushButton(centralwidget);
        viewClothingItems_button->setObjectName("viewClothingItems_button");
        viewClothingItems_button->setGeometry(QRect(820, 80, 141, 24));
        backToMainMeny_button = new QPushButton(centralwidget);
        backToMainMeny_button->setObjectName("backToMainMeny_button");
        backToMainMeny_button->setGeometry(QRect(70, 80, 141, 24));
        ClothingItemsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClothingItemsWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1024, 21));
        ClothingItemsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClothingItemsWindow);
        statusbar->setObjectName("statusbar");
        ClothingItemsWindow->setStatusBar(statusbar);

        retranslateUi(ClothingItemsWindow);

        QMetaObject::connectSlotsByName(ClothingItemsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClothingItemsWindow)
    {
        ClothingItemsWindow->setWindowTitle(QCoreApplication::translate("ClothingItemsWindow", "MainWindow", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ClothingItemsWindow", "JACKETS", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ClothingItemsWindow", "TOPS", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ClothingItemsWindow", "BOTTOMS", nullptr));
        pushButton->setText(QCoreApplication::translate("ClothingItemsWindow", "SHOES", nullptr));
        pageLabel->setText(QCoreApplication::translate("ClothingItemsWindow", "All Items", nullptr));
        viewCloset_button->setText(QCoreApplication::translate("ClothingItemsWindow", "View Closet", nullptr));
        viewClothingItems_button->setText(QCoreApplication::translate("ClothingItemsWindow", "View Saved Outfits", nullptr));
        backToMainMeny_button->setText(QCoreApplication::translate("ClothingItemsWindow", "Back to Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClothingItemsWindow: public Ui_ClothingItemsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOTHINGITEMSWINDOW_H
