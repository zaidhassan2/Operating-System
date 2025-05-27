/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *resourceLabel;
    QCalendarWidget *calendarWidget;
    QLabel *selectedDateLabel;
    QPushButton *closeButton;

    void setupUi(QDialog *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QString::fromUtf8("Calendar"));
        Calendar->resize(600, 500);
        verticalLayout = new QVBoxLayout(Calendar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(Calendar);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        resourceLabel = new QLabel(Calendar);
        resourceLabel->setObjectName(QString::fromUtf8("resourceLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setItalic(true);
        resourceLabel->setFont(font1);
        resourceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(resourceLabel);

        calendarWidget = new QCalendarWidget(Calendar);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        selectedDateLabel = new QLabel(Calendar);
        selectedDateLabel->setObjectName(QString::fromUtf8("selectedDateLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        selectedDateLabel->setFont(font2);
        selectedDateLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(selectedDateLabel);

        closeButton = new QPushButton(Calendar);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setFont(font2);

        verticalLayout->addWidget(closeButton);


        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QDialog *Calendar)
    {
        Calendar->setWindowTitle(QCoreApplication::translate("Calendar", "Mini OS - Calendar", nullptr));
        titleLabel->setText(QCoreApplication::translate("Calendar", "Calendar", nullptr));
        resourceLabel->setText(QCoreApplication::translate("Calendar", "Memory Usage: 0 MB | Process ID: 0", nullptr));
        selectedDateLabel->setText(QCoreApplication::translate("Calendar", "Selected Date: None", nullptr));
        closeButton->setText(QCoreApplication::translate("Calendar", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
