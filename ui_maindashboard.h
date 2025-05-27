/********************************************************************************
** Form generated from reading UI file 'maindashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDASHBOARD_H
#define UI_MAINDASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDashboard
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *memoryLabel;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *textEditorButton;
    QPushButton *calculatorButton;
    QPushButton *resourcesButton;
    QPushButton *gamesButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exitButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainDashboard)
    {
        if (MainDashboard->objectName().isEmpty())
            MainDashboard->setObjectName(QString::fromUtf8("MainDashboard"));
        MainDashboard->resize(800, 600);
        centralwidget = new QWidget(MainDashboard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        memoryLabel = new QLabel(centralwidget);
        memoryLabel->setObjectName(QString::fromUtf8("memoryLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        memoryLabel->setFont(font1);
        memoryLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(memoryLabel);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEditorButton = new QPushButton(centralwidget);
        textEditorButton->setObjectName(QString::fromUtf8("textEditorButton"));
        textEditorButton->setMinimumSize(QSize(150, 150));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        textEditorButton->setFont(font2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/text-editor.png"), QSize(), QIcon::Normal, QIcon::Off);
        textEditorButton->setIcon(icon);
        textEditorButton->setIconSize(QSize(64, 64));

        gridLayout->addWidget(textEditorButton, 0, 0, 1, 1);

        calculatorButton = new QPushButton(centralwidget);
        calculatorButton->setObjectName(QString::fromUtf8("calculatorButton"));
        calculatorButton->setMinimumSize(QSize(150, 150));
        calculatorButton->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        calculatorButton->setIcon(icon1);
        calculatorButton->setIconSize(QSize(64, 64));

        gridLayout->addWidget(calculatorButton, 0, 1, 1, 1);

        resourcesButton = new QPushButton(centralwidget);
        resourcesButton->setObjectName(QString::fromUtf8("resourcesButton"));
        resourcesButton->setMinimumSize(QSize(150, 150));
        resourcesButton->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/resources.png"), QSize(), QIcon::Normal, QIcon::Off);
        resourcesButton->setIcon(icon2);
        resourcesButton->setIconSize(QSize(64, 64));

        gridLayout->addWidget(resourcesButton, 1, 0, 1, 1);

        gamesButton = new QPushButton(centralwidget);
        gamesButton->setObjectName(QString::fromUtf8("gamesButton"));
        gamesButton->setMinimumSize(QSize(150, 150));
        gamesButton->setFont(font2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/games.png"), QSize(), QIcon::Normal, QIcon::Off);
        gamesButton->setIcon(icon3);
        gamesButton->setIconSize(QSize(64, 64));

        gridLayout->addWidget(gamesButton, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font2);

        verticalLayout->addWidget(exitButton);

        MainDashboard->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainDashboard);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainDashboard->setStatusBar(statusbar);

        retranslateUi(MainDashboard);

        QMetaObject::connectSlotsByName(MainDashboard);
    } // setupUi

    void retranslateUi(QMainWindow *MainDashboard)
    {
        MainDashboard->setWindowTitle(QCoreApplication::translate("MainDashboard", "Mini OS - Dashboard", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainDashboard", "Mini OS Dashboard", nullptr));
        memoryLabel->setText(QCoreApplication::translate("MainDashboard", "Memory: 0/0 MB | Disk: 0 MB | CPU: 0 cores", nullptr));
        textEditorButton->setText(QCoreApplication::translate("MainDashboard", "Text Editor", nullptr));
        calculatorButton->setText(QCoreApplication::translate("MainDashboard", "Calculator", nullptr));
        resourcesButton->setText(QCoreApplication::translate("MainDashboard", "Resources", nullptr));
        gamesButton->setText(QCoreApplication::translate("MainDashboard", "Mini Games", nullptr));
        exitButton->setText(QCoreApplication::translate("MainDashboard", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainDashboard: public Ui_MainDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDASHBOARD_H
