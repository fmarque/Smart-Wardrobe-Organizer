/********************************************************************************
** Form generated from reading UI file 'popup1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP1_H
#define UI_POPUP1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_popup1
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *coatButton;
    QPushButton *topButton;
    QPushButton *bottomButton;
    QPushButton *shoesButton;

    void setupUi(QWidget *popup1)
    {
        if (popup1->objectName().isEmpty())
            popup1->setObjectName("popup1");
        popup1->resize(189, 151);
        verticalLayoutWidget = new QWidget(popup1);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 10, 181, 134));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        coatButton = new QPushButton(verticalLayoutWidget);
        coatButton->setObjectName("coatButton");
        coatButton->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 77, 255);"));

        verticalLayout->addWidget(coatButton);

        topButton = new QPushButton(verticalLayoutWidget);
        topButton->setObjectName("topButton");

        verticalLayout->addWidget(topButton);

        bottomButton = new QPushButton(verticalLayoutWidget);
        bottomButton->setObjectName("bottomButton");

        verticalLayout->addWidget(bottomButton);

        shoesButton = new QPushButton(verticalLayoutWidget);
        shoesButton->setObjectName("shoesButton");

        verticalLayout->addWidget(shoesButton);


        retranslateUi(popup1);

        QMetaObject::connectSlotsByName(popup1);
    } // setupUi

    void retranslateUi(QWidget *popup1)
    {
        popup1->setWindowTitle(QCoreApplication::translate("popup1", "Form", nullptr));
        coatButton->setText(QCoreApplication::translate("popup1", "Outerwear", nullptr));
        topButton->setText(QCoreApplication::translate("popup1", "Top", nullptr));
        bottomButton->setText(QCoreApplication::translate("popup1", "Bottom", nullptr));
        shoesButton->setText(QCoreApplication::translate("popup1", "Shoes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class popup1: public Ui_popup1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP1_H
