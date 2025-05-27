/********************************************************************************
** Form generated from reading UI file 'memorystatus.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYSTATUS_H
#define UI_MEMORYSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MemoryStatus
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer;
    QLabel *memoryLabel;
    QProgressBar *memoryProgressBar;
    QSpacerItem *verticalSpacer_2;
    QLabel *diskSpaceLabel;
    QSpacerItem *verticalSpacer_3;
    QLabel *cpuCoresLabel;
    QSpacerItem *verticalSpacer_4;
    QLabel *noteLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *MemoryStatus)
    {
        if (MemoryStatus->objectName().isEmpty())
            MemoryStatus->setObjectName(QString::fromUtf8("MemoryStatus"));
        MemoryStatus->resize(500, 400);
        verticalLayout = new QVBoxLayout(MemoryStatus);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(MemoryStatus);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        memoryLabel = new QLabel(MemoryStatus);
        memoryLabel->setObjectName(QString::fromUtf8("memoryLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        memoryLabel->setFont(font1);

        verticalLayout->addWidget(memoryLabel);

        memoryProgressBar = new QProgressBar(MemoryStatus);
        memoryProgressBar->setObjectName(QString::fromUtf8("memoryProgressBar"));
        memoryProgressBar->setValue(0);

        verticalLayout->addWidget(memoryProgressBar);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        diskSpaceLabel = new QLabel(MemoryStatus);
        diskSpaceLabel->setObjectName(QString::fromUtf8("diskSpaceLabel"));
        diskSpaceLabel->setFont(font1);

        verticalLayout->addWidget(diskSpaceLabel);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        cpuCoresLabel = new QLabel(MemoryStatus);
        cpuCoresLabel->setObjectName(QString::fromUtf8("cpuCoresLabel"));
        cpuCoresLabel->setFont(font1);

        verticalLayout->addWidget(cpuCoresLabel);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        noteLabel = new QLabel(MemoryStatus);
        noteLabel->setObjectName(QString::fromUtf8("noteLabel"));
        QFont font2;
        font2.setItalic(true);
        noteLabel->setFont(font2);
        noteLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(noteLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(MemoryStatus);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MemoryStatus);

        QMetaObject::connectSlotsByName(MemoryStatus);
    } // setupUi

    void retranslateUi(QDialog *MemoryStatus)
    {
        MemoryStatus->setWindowTitle(QCoreApplication::translate("MemoryStatus", "Mini OS - System Resources", nullptr));
        titleLabel->setText(QCoreApplication::translate("MemoryStatus", "System Resources", nullptr));
        memoryLabel->setText(QCoreApplication::translate("MemoryStatus", "Memory Usage: 0/0 MB (0%)", nullptr));
        diskSpaceLabel->setText(QCoreApplication::translate("MemoryStatus", "Disk Space: 0 MB", nullptr));
        cpuCoresLabel->setText(QCoreApplication::translate("MemoryStatus", "CPU Cores: 0", nullptr));
        noteLabel->setText(QCoreApplication::translate("MemoryStatus", "Resources are updated in real-time", nullptr));
        closeButton->setText(QCoreApplication::translate("MemoryStatus", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemoryStatus: public Ui_MemoryStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYSTATUS_H
