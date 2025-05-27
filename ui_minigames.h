/********************************************************************************
** Form generated from reading UI file 'minigames.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIGAMES_H
#define UI_MINIGAMES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniGames
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QStackedWidget *stackedWidget;
    QWidget *gameSelectorPage;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ticTacToeButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *bingoButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *ticTacToePage;
    QVBoxLayout *verticalLayout_3;
    QLabel *gameStatusLabel;
    QGridLayout *ticTacToeLayout;
    QWidget *bingoPage;
    QVBoxLayout *verticalLayout_4;
    QLabel *bingoLabel;
    QLabel *comingSoonLabel;
    QPushButton *closeButton;

    void setupUi(QDialog *MiniGames)
    {
        if (MiniGames->objectName().isEmpty())
            MiniGames->setObjectName(QString::fromUtf8("MiniGames"));
        MiniGames->resize(600, 500);
        verticalLayout = new QVBoxLayout(MiniGames);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(MiniGames);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        stackedWidget = new QStackedWidget(MiniGames);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        gameSelectorPage = new QWidget();
        gameSelectorPage->setObjectName(QString::fromUtf8("gameSelectorPage"));
        verticalLayout_2 = new QVBoxLayout(gameSelectorPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ticTacToeButton = new QPushButton(gameSelectorPage);
        ticTacToeButton->setObjectName(QString::fromUtf8("ticTacToeButton"));
        ticTacToeButton->setMinimumSize(QSize(150, 150));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        ticTacToeButton->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/games.png"), QSize(), QIcon::Normal, QIcon::Off);
        ticTacToeButton->setIcon(icon);
        ticTacToeButton->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(ticTacToeButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        bingoButton = new QPushButton(gameSelectorPage);
        bingoButton->setObjectName(QString::fromUtf8("bingoButton"));
        bingoButton->setMinimumSize(QSize(150, 150));
        bingoButton->setFont(font1);
        bingoButton->setIcon(icon);
        bingoButton->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(bingoButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(gameSelectorPage);
        ticTacToePage = new QWidget();
        ticTacToePage->setObjectName(QString::fromUtf8("ticTacToePage"));
        verticalLayout_3 = new QVBoxLayout(ticTacToePage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gameStatusLabel = new QLabel(ticTacToePage);
        gameStatusLabel->setObjectName(QString::fromUtf8("gameStatusLabel"));
        gameStatusLabel->setFont(font1);
        gameStatusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(gameStatusLabel);

        ticTacToeLayout = new QGridLayout();
        ticTacToeLayout->setObjectName(QString::fromUtf8("ticTacToeLayout"));

        verticalLayout_3->addLayout(ticTacToeLayout);

        stackedWidget->addWidget(ticTacToePage);
        bingoPage = new QWidget();
        bingoPage->setObjectName(QString::fromUtf8("bingoPage"));
        verticalLayout_4 = new QVBoxLayout(bingoPage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        bingoLabel = new QLabel(bingoPage);
        bingoLabel->setObjectName(QString::fromUtf8("bingoLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        bingoLabel->setFont(font2);
        bingoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(bingoLabel);

        comingSoonLabel = new QLabel(bingoPage);
        comingSoonLabel->setObjectName(QString::fromUtf8("comingSoonLabel"));
        QFont font3;
        font3.setPointSize(12);
        font3.setItalic(true);
        comingSoonLabel->setFont(font3);
        comingSoonLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(comingSoonLabel);

        stackedWidget->addWidget(bingoPage);

        verticalLayout->addWidget(stackedWidget);

        closeButton = new QPushButton(MiniGames);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout->addWidget(closeButton);


        retranslateUi(MiniGames);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MiniGames);
    } // setupUi

    void retranslateUi(QDialog *MiniGames)
    {
        MiniGames->setWindowTitle(QCoreApplication::translate("MiniGames", "Mini OS - Mini Games", nullptr));
        titleLabel->setText(QCoreApplication::translate("MiniGames", "Mini Games", nullptr));
        ticTacToeButton->setText(QCoreApplication::translate("MiniGames", "Tic Tac Toe", nullptr));
        bingoButton->setText(QCoreApplication::translate("MiniGames", "Bingo", nullptr));
        gameStatusLabel->setText(QCoreApplication::translate("MiniGames", "Tic Tac Toe - Player X's turn", nullptr));
        bingoLabel->setText(QCoreApplication::translate("MiniGames", "Bingo Game", nullptr));
        comingSoonLabel->setText(QCoreApplication::translate("MiniGames", "Coming Soon!", nullptr));
        closeButton->setText(QCoreApplication::translate("MiniGames", "Back to Game Selection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MiniGames: public Ui_MiniGames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIGAMES_H
