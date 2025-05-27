/********************************************************************************
** Form generated from reading UI file 'modeselection.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODESELECTION_H
#define UI_MODESELECTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModeSelection
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *kernelButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *userButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *infoLabel;

    void setupUi(QDialog *ModeSelection)
    {
        if (ModeSelection->objectName().isEmpty())
            ModeSelection->setObjectName(QString::fromUtf8("ModeSelection"));
        ModeSelection->resize(500, 400);
        verticalLayout = new QVBoxLayout(ModeSelection);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(ModeSelection);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        subtitleLabel = new QLabel(ModeSelection);
        subtitleLabel->setObjectName(QString::fromUtf8("subtitleLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        subtitleLabel->setFont(font1);
        subtitleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(subtitleLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        kernelButton = new QPushButton(ModeSelection);
        kernelButton->setObjectName(QString::fromUtf8("kernelButton"));
        kernelButton->setMinimumSize(QSize(120, 120));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        kernelButton->setFont(font2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/kernel.png"), QSize(), QIcon::Normal, QIcon::Off);
        kernelButton->setIcon(icon);
        kernelButton->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(kernelButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        userButton = new QPushButton(ModeSelection);
        userButton->setObjectName(QString::fromUtf8("userButton"));
        userButton->setMinimumSize(QSize(120, 120));
        userButton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        userButton->setIcon(icon1);
        userButton->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(userButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        infoLabel = new QLabel(ModeSelection);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        QFont font3;
        font3.setItalic(true);
        infoLabel->setFont(font3);
        infoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(infoLabel);


        retranslateUi(ModeSelection);

        QMetaObject::connectSlotsByName(ModeSelection);
    } // setupUi

    void retranslateUi(QDialog *ModeSelection)
    {
        ModeSelection->setWindowTitle(QCoreApplication::translate("ModeSelection", "Mini OS - Mode Selection", nullptr));
        titleLabel->setText(QCoreApplication::translate("ModeSelection", "Welcome to Mini OS", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("ModeSelection", "Please select operating mode:", nullptr));
        kernelButton->setText(QCoreApplication::translate("ModeSelection", "Kernel Mode", nullptr));
        userButton->setText(QCoreApplication::translate("ModeSelection", "User Mode", nullptr));
        infoLabel->setText(QCoreApplication::translate("ModeSelection", "Kernel Mode provides administrative privileges", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModeSelection: public Ui_ModeSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODESELECTION_H
