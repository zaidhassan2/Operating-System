#include "systeminfo.h"
#include "ui_systeminfo.h"
#include <QMessageBox>
#include <QDateTime>

SystemInfo::SystemInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemInfo)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - System Information");
    setFixedSize(600, 500);
    
    // Set up timer to update system resources
    resourceTimer = new QTimer(this);
    connect(resourceTimer, &QTimer::timeout, this, &SystemInfo::updateSystemResources);
    resourceTimer->start(1000);
    
    // Initial updates
    updateSystemResources();
    refreshSystemInfo();
    
    // Connect buttons
    connect(ui->refreshButton, &QPushButton::clicked, this, &SystemInfo::on_refreshButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &SystemInfo::on_closeButton_clicked);
}

SystemInfo::~SystemInfo()
{
    // Deduct memory usage when closing
    SharedMemory::instance().releaseMemory(3);
    delete ui;
}

void SystemInfo::on_refreshButton_clicked()
{
    refreshSystemInfo();
}

void SystemInfo::on_closeButton_clicked()
{
    accept();
}

void SystemInfo::updateSystemResources()
{
    // Allocate memory for this application (if not already allocated)
    static bool memoryAllocated = false;
    if (!memoryAllocated) {
        SharedMemory::instance().allocateMemory(3);
        memoryAllocated = true;
    }
    
    // Update resource info
    ui->resourceLabel->setText(QString("Memory Usage: 3 MB | Process ID: %1").arg(qrand() % 1000 + 7000));
}

void SystemInfo::refreshSystemInfo()
{
    ui->osInfoText->setText(getOSInformation());
    ui->cpuInfoText->setText(getCPUInformation());
    ui->memoryInfoText->setText(getMemoryInformation());
    ui->storageInfoText->setText(getStorageInformation());
    ui->networkInfoText->setText(getNetworkInformation());
    
    ui->lastUpdatedLabel->setText("Last Updated: " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

QString SystemInfo::getOSInformation()
{
    return "OS: Mini OS 1.0\n"
           "Kernel: MYOS Kernel 1.0\n"
           "Architecture: Virtual x86_64\n"
           "Hostname: MYOS-VM\n"
           "User: myos-user";
}

QString SystemInfo::getCPUInformation()
{
    return "CPU Model: Mini CPU @ 2.4 GHz\n"
           "Cores: 4\n"
           "Threads: 8\n"
           "Current Usage: 15%\n"
           "Cache: 8MB L3";
}

QString SystemInfo::getMemoryInformation()
{
    int availableMemory = SharedMemory::instance().getAvailableMemory();
    int totalMemory = SharedMemory::instance().getTotalMemory();
    int usedMemory = totalMemory - availableMemory;
    int percentUsed = (usedMemory * 100) / totalMemory;
    
    return QString("Total RAM: %1 MB\n"
                   "Used RAM: %2 MB\n"
                   "Available RAM: %3 MB\n"
                   "Percent Used: %4%\n"
                   "Swap: 2048 MB")
            .arg(totalMemory)
            .arg(usedMemory)
            .arg(availableMemory)
            .arg(percentUsed);
}

QString SystemInfo::getStorageInformation()
{
    int diskSpace = SharedMemory::instance().getDiskSpace();
    int usedSpace = diskSpace / 3;
    int availableSpace = diskSpace - usedSpace;
    int percentUsed = (usedSpace * 100) / diskSpace;
    
    return QString("Total Disk: %1 MB\n"
                   "Used: %2 MB\n"
                   "Available: %3 MB\n"
                   "Percent Used: %4%\n"
                   "File System: MyFS")
            .arg(diskSpace)
            .arg(usedSpace)
            .arg(availableSpace)
            .arg(percentUsed);
}

QString SystemInfo::getNetworkInformation()
{
    return "Network Interface: eth0\n"
           "IP Address: 192.168.1.100\n"
           "Subnet Mask: 255.255.255.0\n"
           "Gateway: 192.168.1.1\n"
           "DNS: 8.8.8.8\n"
           "MAC Address: 00:11:22:33:44:55";
}