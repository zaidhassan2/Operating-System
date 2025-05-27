#include "pcbtable.h"
#include "ui_pcbtable.h"
#include <QMessageBox>
#include <QDateTime>
#include <QInputDialog>
#include <QRandomGenerator>

PCBTable::PCBTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCBTable)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Process Control Block Table");
    setFixedSize(800, 600);
    
    // Set up timer to update system resources
    resourceTimer = new QTimer(this);
    connect(resourceTimer, &QTimer::timeout, this, &PCBTable::updateSystemResources);
    resourceTimer->start(1000);
    
    // Set up timer to automatically update the process table
    updateTableTimer = new QTimer(this);
    connect(updateTableTimer, &QTimer::timeout, this, &PCBTable::updateProcessTable);
    updateTableTimer->start(3000);  // Update every 3 seconds
    
    // Connect buttons
    connect(ui->refreshButton, &QPushButton::clicked, this, &PCBTable::on_refreshButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &PCBTable::on_closeButton_clicked);
    connect(ui->killProcessButton, &QPushButton::clicked, this, &PCBTable::killProcess);
    connect(ui->priorityButton, &QPushButton::clicked, this, &PCBTable::changePriority);
    
    // Initial updates
    updateSystemResources();
    generateSampleProcesses();
    refreshProcessTable();
}

PCBTable::~PCBTable()
{
    // Deduct memory usage when closing
    SharedMemory::instance().releaseMemory(4);
    delete ui;
}

void PCBTable::on_refreshButton_clicked()
{
    refreshProcessTable();
}

void PCBTable::on_closeButton_clicked()
{
    accept();
}

void PCBTable::updateSystemResources()
{
    // Allocate memory for this application (if not already allocated)
    static bool memoryAllocated = false;
    if (!memoryAllocated) {
        SharedMemory::instance().allocateMemory(4);
        memoryAllocated = true;
    }
    
    // Update resource info
    ui->resourceLabel->setText(QString("Memory Usage: 4 MB | Process ID: %1").arg(qrand() % 1000 + 8000));
}

void PCBTable::generateSampleProcesses()
{
    // Clear existing processes
    processes.clear();
    
    // System processes
    PCBEntry kernel;
    kernel.pid = 1;
    kernel.name = "kernel";
    kernel.state = "Running";
    kernel.priority = 0;
    kernel.memory = 24;
    kernel.startTime = "System Boot";
    kernel.cpuTime = "00:45:32";
    processes.append(kernel);
    
    PCBEntry systemd;
    systemd.pid = 2;
    systemd.name = "systemd";
    systemd.state = "Running";
    systemd.priority = 1;
    systemd.memory = 12;
    systemd.startTime = "System Boot";
    systemd.cpuTime = "00:45:30";
    processes.append(systemd);
    
    // Add user processes
    QStringList processNames = {"calculator", "text_editor", "calendar", "clock", 
                               "browser", "file_manager", "terminal", "system_monitor"};
    
    for(int i = 0; i < processNames.size(); i++) {
        if(QRandomGenerator::global()->bounded(100) > 40) { // 60% chance to include
            PCBEntry process;
            process.pid = 100 + i;
            process.name = processNames[i];
            process.state = getRandomState();
            process.priority = getRandomNumber(1, 10);
            process.memory = getRandomNumber(1, 20);
            
            // Create a random start time within the last hour
            QDateTime now = QDateTime::currentDateTime();
            int randomSeconds = getRandomNumber(0, 3600);
            QDateTime startTime = now.addSecs(-randomSeconds);
            process.startTime = startTime.toString("hh:mm:ss");
            
            // Random CPU time less than time since start
            int cpuSeconds = getRandomNumber(0, randomSeconds);
            QTime cpuTime(0, 0, 0);
            cpuTime = cpuTime.addSecs(cpuSeconds);
            process.cpuTime = cpuTime.toString("hh:mm:ss");
            
            processes.append(process);
        }
    }
}

void PCBTable::refreshProcessTable()
{
    // Clear the table
    ui->processTable->setRowCount(0);
    
    // Fill the table with process data
    for(int i = 0; i < processes.size(); i++) {
        ui->processTable->insertRow(i);
        
        ui->processTable->setItem(i, 0, new QTableWidgetItem(QString::number(processes[i].pid)));
        ui->processTable->setItem(i, 1, new QTableWidgetItem(processes[i].name));
        ui->processTable->setItem(i, 2, new QTableWidgetItem(processes[i].state));
        ui->processTable->setItem(i, 3, new QTableWidgetItem(QString::number(processes[i].priority)));
        ui->processTable->setItem(i, 4, new QTableWidgetItem(QString::number(processes[i].memory) + " MB"));
        ui->processTable->setItem(i, 5, new QTableWidgetItem(processes[i].startTime));
        ui->processTable->setItem(i, 6, new QTableWidgetItem(processes[i].cpuTime));
    }
    
    // Update process statistics
    int runningCount = 0;
    int waitingCount = 0;
    int blockedCount = 0;
    
    for(const PCBEntry& process : processes) {
        if(process.state == "Running") runningCount++;
        else if(process.state == "Waiting") waitingCount++;
        else if(process.state == "Blocked") blockedCount++;
    }
    
    ui->statsLabel->setText(QString("Total: %1 | Running: %2 | Waiting: %3 | Blocked: %4")
                           .arg(processes.size())
                           .arg(runningCount)
                           .arg(waitingCount)
                           .arg(blockedCount));
}

void PCBTable::updateProcessTable()
{
    // Randomly change some process states
    for(int i = 2; i < processes.size(); i++) {  // Skip kernel and systemd
        if(QRandomGenerator::global()->bounded(100) > 70) {  // 30% chance to change state
            processes[i].state = getRandomState();
            
            // Randomly update CPU time
            QTime cpuTime = QTime::fromString(processes[i].cpuTime, "hh:mm:ss");
            cpuTime = cpuTime.addSecs(getRandomNumber(1, 10));
            processes[i].cpuTime = cpuTime.toString("hh:mm:ss");
        }
    }
    
    refreshProcessTable();
}

void PCBTable::killProcess()
{
    int row = ui->processTable->currentRow();
    if(row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a process to kill.");
        return;
    }
    
    int pid = ui->processTable->item(row, 0)->text().toInt();
    QString name = ui->processTable->item(row, 1)->text();
    
    // Don't allow killing system processes
    if(pid <= 2) {
        QMessageBox::critical(this, "Permission Denied", 
                             "Cannot kill system processes (PID <= 2).");
        return;
    }
    
    // Ask for confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Kill", 
                                 QString("Are you sure you want to kill process %1 (%2)?")
                                 .arg(name).arg(pid),
                                 QMessageBox::Yes|QMessageBox::No);
    
    if(reply == QMessageBox::Yes) {
        // Remove the process
        for(int i = 0; i < processes.size(); i++) {
            if(processes[i].pid == pid) {
                processes.remove(i);
                break;
            }
        }
        refreshProcessTable();
        
        QMessageBox::information(this, "Process Killed", 
                                QString("Process %1 (PID: %2) has been terminated.")
                                .arg(name).arg(pid));
    }
}

void PCBTable::changePriority()
{
    int row = ui->processTable->currentRow();
    if(row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a process to change priority.");
        return;
    }
    
    int pid = ui->processTable->item(row, 0)->text().toInt();
    QString name = ui->processTable->item(row, 1)->text();
    int currentPriority = ui->processTable->item(row, 3)->text().toInt();
    
    // Don't allow changing system process priorities
    if(pid <= 2) {
        QMessageBox::critical(this, "Permission Denied", 
                             "Cannot change priority of system processes (PID <= 2).");
        return;
    }
    
    // Ask for new priority
    bool ok;
    int newPriority = QInputDialog::getInt(this, "Change Priority",
                                         QString("Enter new priority for %1 (PID: %2):")
                                         .arg(name).arg(pid),
                                         currentPriority, 1, 20, 1, &ok);
    
    if(ok) {
        // Update the priority
        for(int i = 0; i < processes.size(); i++) {
            if(processes[i].pid == pid) {
                processes[i].priority = newPriority;
                break;
            }
        }
        refreshProcessTable();
        
        QMessageBox::information(this, "Priority Changed", 
                                QString("Process %1 (PID: %2) priority changed to %3.")
                                .arg(name).arg(pid).arg(newPriority));
    }
}

int PCBTable::getRandomNumber(int min, int max)
{
    return QRandomGenerator::global()->bounded(min, max + 1);
}

QString PCBTable::getRandomState()
{
    QStringList states = {"Running", "Waiting", "Blocked", "Ready"};
    int index = QRandomGenerator::global()->bounded(states.size());
    return states[index];
}