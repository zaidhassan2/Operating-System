#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QDialog>
#include <QTimer>
#include <QProcess>
#include "sharedmemory.h"

namespace Ui {
class SystemInfo;
}

class SystemInfo : public QDialog
{
    Q_OBJECT

public:
    explicit SystemInfo(QWidget *parent = nullptr);
    ~SystemInfo();

private slots:
    void on_refreshButton_clicked();
    void on_closeButton_clicked();
    void updateSystemResources();

private:
    Ui::SystemInfo *ui;
    QTimer *resourceTimer;
    void refreshSystemInfo();
    QString getOSInformation();
    QString getCPUInformation();
    QString getMemoryInformation();
    QString getStorageInformation();
    QString getNetworkInformation();
};

#endif // SYSTEMINFO_H