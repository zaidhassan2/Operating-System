/********************************************************************************
** Form generated from reading UI file 'clock.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCK_H
#define UI_CLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Clock
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *resourceLabel;
    QLabel *timeLabel;
    QLabel *dateLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *formatToggleButton;
    QPushButton *alarmButton;
    QSpacerItem *verticalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *Clock)
    {
        if (Clock->objectName().isEmpty())
            Clock->setObjectName(QString::fromUtf8("Clock"));
        Clock->resize(400, 300);
        verticalLayout = new QVBoxLayout(Clock);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(Clock);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        resourceLabel = new QLabel(Clock);
        resourceLabel->setObjectName(QString::fromUtf8("resourceLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setItalic(true);
        resourceLabel->setFont(font1);
        resourceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(resourceLabel);

        timeLabel = new QLabel(Clock);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        timeLabel->setFont(font2);
        timeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(timeLabel);

        dateLabel = new QLabel(Clock);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(14);
        dateLabel->setFont(font3);
        dateLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(dateLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formatToggleButton = new QPushButton(Clock);
        formatToggleButton->setObjectName(QString::fromUtf8("formatToggleButton"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(10);
        formatToggleButton->setFont(font4);

        horizontalLayout->addWidget(formatToggleButton);

        alarmButton = new QPushButton(Clock);
        alarmButton->setObjectName(QString::fromUtf8("alarmButton"));
        alarmButton->setFont(font4);

        horizontalLayout->addWidget(alarmButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        closeButton = new QPushButton(Clock);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(12);
        closeButton->setFont(font5);

        verticalLayout->addWidget(closeButton);


        retranslateUi(Clock);

        QMetaObject::connectSlotsByName(Clock);
    } // setupUi

    void retranslateUi(QDialog *Clock)
    {
        Clock->setWindowTitle(QCoreApplication::translate("Clock", "Mini OS - Clock", nullptr));
        titleLabel->setText(QCoreApplication::translate("Clock", "Clock", nullptr));
        resourceLabel->setText(QCoreApplication::translate("Clock", "Memory Usage: 0 MB | Process ID: 0", nullptr));
        timeLabel->setText(QCoreApplication::translate("Clock", "00:00:00", nullptr));
        dateLabel->setText(QCoreApplication::translate("Clock", "Monday, January 1, 2024", nullptr));
        formatToggleButton->setText(QCoreApplication::translate("Clock", "Switch to 24-Hour", nullptr));
        alarmButton->setText(QCoreApplication::translate("Clock", "Set Alarm", nullptr));
        closeButton->setText(QCoreApplication::translate("Clock", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clock: public Ui_Clock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
