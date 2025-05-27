/********************************************************************************
** Form generated from reading UI file 'filebrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEBROWSER_H
#define UI_FILEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *resourceLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *homeButton;
    QPushButton *refreshButton;
    QSpacerItem *horizontalSpacer;
    QLabel *pathLabel;
    QListWidget *fileListWidget;
    QLabel *statsLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createButton;
    QPushButton *deleteButton;
    QPushButton *closeButton;

    void setupUi(QDialog *FileBrowser)
    {
        if (FileBrowser->objectName().isEmpty())
            FileBrowser->setObjectName(QString::fromUtf8("FileBrowser"));
        FileBrowser->resize(700, 500);
        verticalLayout = new QVBoxLayout(FileBrowser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(FileBrowser);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        resourceLabel = new QLabel(FileBrowser);
        resourceLabel->setObjectName(QString::fromUtf8("resourceLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setItalic(true);
        resourceLabel->setFont(font1);
        resourceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(resourceLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QPushButton(FileBrowser);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton);

        homeButton = new QPushButton(FileBrowser);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));

        horizontalLayout->addWidget(homeButton);

        refreshButton = new QPushButton(FileBrowser);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        horizontalLayout->addWidget(refreshButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        pathLabel = new QLabel(FileBrowser);
        pathLabel->setObjectName(QString::fromUtf8("pathLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        pathLabel->setFont(font2);

        verticalLayout->addWidget(pathLabel);

        fileListWidget = new QListWidget(FileBrowser);
        fileListWidget->setObjectName(QString::fromUtf8("fileListWidget"));

        verticalLayout->addWidget(fileListWidget);

        statsLabel = new QLabel(FileBrowser);
        statsLabel->setObjectName(QString::fromUtf8("statsLabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(9);
        statsLabel->setFont(font3);

        verticalLayout->addWidget(statsLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        createButton = new QPushButton(FileBrowser);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(10);
        createButton->setFont(font4);

        horizontalLayout_2->addWidget(createButton);

        deleteButton = new QPushButton(FileBrowser);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setFont(font4);

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout_2);

        closeButton = new QPushButton(FileBrowser);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(12);
        closeButton->setFont(font5);

        verticalLayout->addWidget(closeButton);


        retranslateUi(FileBrowser);

        QMetaObject::connectSlotsByName(FileBrowser);
    } // setupUi

    void retranslateUi(QDialog *FileBrowser)
    {
        FileBrowser->setWindowTitle(QCoreApplication::translate("FileBrowser", "Mini OS - File Browser", nullptr));
        titleLabel->setText(QCoreApplication::translate("FileBrowser", "File Browser", nullptr));
        resourceLabel->setText(QCoreApplication::translate("FileBrowser", "Memory Usage: 0 MB | Process ID: 0", nullptr));
        backButton->setText(QCoreApplication::translate("FileBrowser", "Back", nullptr));
        homeButton->setText(QCoreApplication::translate("FileBrowser", "Home", nullptr));
        refreshButton->setText(QCoreApplication::translate("FileBrowser", "Refresh", nullptr));
        pathLabel->setText(QCoreApplication::translate("FileBrowser", "Location: /", nullptr));
        statsLabel->setText(QCoreApplication::translate("FileBrowser", "Directories: 0 | Files: 0 | Total Size: 0 KB", nullptr));
        createButton->setText(QCoreApplication::translate("FileBrowser", "Create New", nullptr));
        deleteButton->setText(QCoreApplication::translate("FileBrowser", "Delete", nullptr));
        closeButton->setText(QCoreApplication::translate("FileBrowser", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileBrowser: public Ui_FileBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEBROWSER_H
