#ifndef PCBTABLE_H
#define PCBTABLE_H

#include <QDialog>
#include <QTimer>
#include <QVector>
#include <QTableWidgetItem>
#include "sharedmemory.h"

// Define a struct to represent a Process Control Block
struct PCBEntry {
    int pid;
    QString name;
    QString state;
    int priority;
    int memory;
    QString startTime;
    QString cpuTime;
};

namespace Ui {
class PCBTable;
}

class PCBTable : public QDialog
{
    Q_OBJECT

public:
    explicit PCBTable(QWidget *parent = nullptr);
    ~PCBTable();

private slots:
    void on_refreshButton_clicked();
    void on_closeButton_clicked();
    void updateSystemResources();
    void killProcess();
    void changePriority();

private:
    Ui::PCBTable *ui;
    QTimer *resourceTimer;
    QTimer *updateTableTimer;
    QVector<PCBEntry> processes;
    
    void refreshProcessTable();
    void generateSampleProcesses();
    void updateProcessTable();
    int getRandomNumber(int min, int max);
    QString getRandomState();
};

#endif // PCBTABLE_H