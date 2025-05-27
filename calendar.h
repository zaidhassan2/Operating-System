#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include <QCalendarWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDate>
#include "sharedmemory.h"

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_dateSelected(const QDate &date);
    void on_closeButton_clicked();
    void updateSystemResources();

private:
    Ui::Calendar *ui;
    QTimer *resourceTimer;
};

#endif // CALENDAR_H