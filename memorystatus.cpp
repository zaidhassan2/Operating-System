#include "memorystatus.h"
#include "ui_memorystatus.h"

MemoryStatus::MemoryStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryStatus)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - System Resources");
    setFixedSize(500, 400);
    
    // Check if there's enough memory to run this application
    if (!checkMemoryAvailable(100)) {
        QMessageBox::warning(this, "Insufficient Resources", 
                            "Not enough memory available to launch Resource Monitor.\n"
                            "Required: 100 MB\n"
                            "Available: " + QString::number(SharedMemory::instance().getAvailableMemory()) + " MB");
        reject();
        return;
    }
    
    // Allocate memory for running the application
    SharedMemory::instance().allocateMemory(100);
    
    // Update the resource display
    updateResourceDisplay();
    
    // Set up the timer to update resource information
    resourceTimer = new QTimer(this);
    connect(resourceTimer, &QTimer::timeout, this, &MemoryStatus::updateResourceDisplay);
    resourceTimer->start(1000);  // Update every second
}

MemoryStatus::~MemoryStatus()
{
    // Release allocated memory when closing
    SharedMemory::instance().releaseMemory(100);
    delete ui;
}

bool MemoryStatus::checkMemoryAvailable(int requiredMemory)
{
    return SharedMemory::instance().getAvailableMemory() >= requiredMemory;
}

void MemoryStatus::updateResourceDisplay()
{
    int totalMemory = SharedMemory::instance().getTotalMemory();
    int availableMemory = SharedMemory::instance().getAvailableMemory();
    int usedMemory = totalMemory - availableMemory;
    int diskSpace = SharedMemory::instance().getDiskSpace();
    int cpuCores = SharedMemory::instance().getCpuCores();
    
    // Update memory progress bar
    ui->memoryProgressBar->setMaximum(totalMemory);
    ui->memoryProgressBar->setValue(usedMemory);
    ui->memoryLabel->setText(QString("Memory Usage: %1/%2 MB (%3%)")
                            .arg(usedMemory)
                            .arg(totalMemory)
                            .arg((double)usedMemory * 100 / totalMemory, 0, 'f', 1));
    
    // Update disk and CPU information
    ui->diskSpaceLabel->setText(QString("Disk Space: %1 MB").arg(diskSpace));
    ui->cpuCoresLabel->setText(QString("CPU Cores: %1").arg(cpuCores));
}

void MemoryStatus::on_closeButton_clicked()
{
    accept();
}
