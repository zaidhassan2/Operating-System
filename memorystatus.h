#ifndef MEMORYSTATUS_H
#define MEMORYSTATUS_H

#include <QDialog>

#include <QTimer>
#include <QMessageBox>
#include "sharedmemory.h"

namespace Ui {
class MemoryStatus;
}

class MemoryStatus : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryStatus(QWidget *parent = nullptr);
    ~MemoryStatus();

private slots:
    void updateResourceDisplay();
    void on_closeButton_clicked();

private:
    Ui::MemoryStatus *ui;
    QTimer *resourceTimer;
    bool checkMemoryAvailable(int requiredMemory);
};

#endif // MEMORYSTATUS_H
