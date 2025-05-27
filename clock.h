#ifndef CLOCK_H
#define CLOCK_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QLabel>
#include <QPushButton>
#include "sharedmemory.h"

namespace Ui {
class Clock;
}

class Clock : public QDialog
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = nullptr);
    ~Clock();

private slots:
    void updateTime();
    void on_alarmButton_clicked();
    void on_closeButton_clicked();
    void updateSystemResources();

private:
    Ui::Clock *ui;
    QTimer *timeUpdateTimer;
    QTimer *resourceTimer;
    bool is24HourFormat;
};

#endif // CLOCK_H