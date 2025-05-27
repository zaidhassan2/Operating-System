#include "resourceallocation.h"
#include "ui_resourceallocation.h"
#include <QMessageBox>

ResourceAllocation::ResourceAllocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResourceAllocation)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Resource Allocation");
    setFixedSize(500, 400);
}

ResourceAllocation::~ResourceAllocation()
{
    delete ui;
}

void ResourceAllocation::on_allocateButton_clicked()
{
    bool memoryOk = false;
    bool diskOk = false;
    bool coresOk = false;
    
    int memory = ui->memorySpinBox->value();
    int diskSpace = ui->diskSpaceSpinBox->value();
    int cpuCores = ui->cpuCoresSpinBox->value();
    
    if (memory <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount of memory.");
        return;
    }
    
    if (diskSpace <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid amount of disk space.");
        return;
    }
    
    if (cpuCores <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid number of CPU cores.");
        return;
    }
    
    // Store the resource values in shared memory
    SharedMemory::instance().setTotalMemory(memory);
    SharedMemory::instance().setDiskSpace(diskSpace);
    SharedMemory::instance().setCpuCores(cpuCores);
    
    QMessageBox::information(this, "Resource Allocation", 
        "Resources allocated successfully:\n"
        "Memory: " + QString::number(memory) + " MB\n"
        "Disk Space: " + QString::number(diskSpace) + " MB\n"
        "CPU Cores: " + QString::number(cpuCores));
    
    accept();
}
