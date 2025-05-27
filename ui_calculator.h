/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLineEdit *displayLineEdit;
    QGridLayout *gridLayout;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *buttonDivide;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *buttonMultiply;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *buttonMinus;
    QPushButton *buttonClear;
    QPushButton *button0;
    QPushButton *buttonEquals;
    QPushButton *buttonPlus;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(300, 400);
        verticalLayout = new QVBoxLayout(Calculator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(Calculator);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        displayLineEdit = new QLineEdit(Calculator);
        displayLineEdit->setObjectName(QString::fromUtf8("displayLineEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(18);
        displayLineEdit->setFont(font1);
        displayLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        displayLineEdit->setReadOnly(true);

        verticalLayout->addWidget(displayLineEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button7 = new QPushButton(Calculator);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setMinimumSize(QSize(0, 40));
        button7->setFont(font);

        gridLayout->addWidget(button7, 0, 0, 1, 1);

        button8 = new QPushButton(Calculator);
        button8->setObjectName(QString::fromUtf8("button8"));
        button8->setMinimumSize(QSize(0, 40));
        button8->setFont(font);

        gridLayout->addWidget(button8, 0, 1, 1, 1);

        button9 = new QPushButton(Calculator);
        button9->setObjectName(QString::fromUtf8("button9"));
        button9->setMinimumSize(QSize(0, 40));
        button9->setFont(font);

        gridLayout->addWidget(button9, 0, 2, 1, 1);

        buttonDivide = new QPushButton(Calculator);
        buttonDivide->setObjectName(QString::fromUtf8("buttonDivide"));
        buttonDivide->setMinimumSize(QSize(0, 40));
        buttonDivide->setFont(font);

        gridLayout->addWidget(buttonDivide, 0, 3, 1, 1);

        button4 = new QPushButton(Calculator);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setMinimumSize(QSize(0, 40));
        button4->setFont(font);

        gridLayout->addWidget(button4, 1, 0, 1, 1);

        button5 = new QPushButton(Calculator);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setMinimumSize(QSize(0, 40));
        button5->setFont(font);

        gridLayout->addWidget(button5, 1, 1, 1, 1);

        button6 = new QPushButton(Calculator);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setMinimumSize(QSize(0, 40));
        button6->setFont(font);

        gridLayout->addWidget(button6, 1, 2, 1, 1);

        buttonMultiply = new QPushButton(Calculator);
        buttonMultiply->setObjectName(QString::fromUtf8("buttonMultiply"));
        buttonMultiply->setMinimumSize(QSize(0, 40));
        buttonMultiply->setFont(font);

        gridLayout->addWidget(buttonMultiply, 1, 3, 1, 1);

        button1 = new QPushButton(Calculator);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setMinimumSize(QSize(0, 40));
        button1->setFont(font);

        gridLayout->addWidget(button1, 2, 0, 1, 1);

        button2 = new QPushButton(Calculator);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setMinimumSize(QSize(0, 40));
        button2->setFont(font);

        gridLayout->addWidget(button2, 2, 1, 1, 1);

        button3 = new QPushButton(Calculator);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setMinimumSize(QSize(0, 40));
        button3->setFont(font);

        gridLayout->addWidget(button3, 2, 2, 1, 1);

        buttonMinus = new QPushButton(Calculator);
        buttonMinus->setObjectName(QString::fromUtf8("buttonMinus"));
        buttonMinus->setMinimumSize(QSize(0, 40));
        buttonMinus->setFont(font);

        gridLayout->addWidget(buttonMinus, 2, 3, 1, 1);

        buttonClear = new QPushButton(Calculator);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setMinimumSize(QSize(0, 40));
        buttonClear->setFont(font);

        gridLayout->addWidget(buttonClear, 3, 0, 1, 1);

        button0 = new QPushButton(Calculator);
        button0->setObjectName(QString::fromUtf8("button0"));
        button0->setMinimumSize(QSize(0, 40));
        button0->setFont(font);

        gridLayout->addWidget(button0, 3, 1, 1, 1);

        buttonEquals = new QPushButton(Calculator);
        buttonEquals->setObjectName(QString::fromUtf8("buttonEquals"));
        buttonEquals->setMinimumSize(QSize(0, 40));
        buttonEquals->setFont(font);

        gridLayout->addWidget(buttonEquals, 3, 2, 1, 1);

        buttonPlus = new QPushButton(Calculator);
        buttonPlus->setObjectName(QString::fromUtf8("buttonPlus"));
        buttonPlus->setMinimumSize(QSize(0, 40));
        buttonPlus->setFont(font);

        gridLayout->addWidget(buttonPlus, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(Calculator);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QDialog *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Mini OS - Calculator", nullptr));
        titleLabel->setText(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        button7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        button8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        button9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        buttonDivide->setText(QCoreApplication::translate("Calculator", "/", nullptr));
        button4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        button5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        button6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        buttonMultiply->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        button1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        button2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        button3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        buttonMinus->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        buttonClear->setText(QCoreApplication::translate("Calculator", "C", nullptr));
        button0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        buttonEquals->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        buttonPlus->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        closeButton->setText(QCoreApplication::translate("Calculator", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
