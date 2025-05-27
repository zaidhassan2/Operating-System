#include "clock.h"
#include "ui_clock.h"
#include <QMessageBox>

Clock::Clock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clock),
    is24HourFormat(false)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Clock");
    setFixedSize(400, 300);
    
    // Set up timer to update clock every second
    timeUpdateTimer = new QTimer(this);
    connect(timeUpdateTimer, &QTimer::timeout, this, &Clock::updateTime);
    timeUpdateTimer->start(1000);
    
    // Set up timer to update system resources
    resourceTimer = new QTimer(this);
    connect(resourceTimer, &QTimer::timeout, this, &Clock::updateSystemResources);
    resourceTimer->start(1000);
    
    // Initial updates
    updateTime();
    updateSystemResources();
    
    // Connect buttons
    connect(ui->formatToggleButton, &QPushButton::clicked, [this]() {
        is24HourFormat = !is24HourFormat;
        updateTime();
    });
    
    connect(ui->alarmButton, &QPushButton::clicked, this, &Clock::on_alarmButton_clicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &Clock::on_closeButton_clicked);
}

Clock::~Clock()
{
    // Deduct memory usage when closing
    SharedMemory::instance().releaseMemory(1);
    delete ui;
}

void Clock::updateTime()
{
    QTime currentTime = QTime::currentTime();
    QDate currentDate = QDate::currentDate();
    
    // Format time based on 12/24-hour selection
    QString timeFormat = is24HourFormat ? "hh:mm:ss" : "hh:mm:ss AP";
    
    ui->timeLabel->setText(currentTime.toString(timeFormat));
    ui->dateLabel->setText(currentDate.toString("dddd, MMMM d, yyyy"));
    
    // Update format button text
    ui->formatToggleButton->setText(is24HourFormat ? "Switch to 12-Hour" : "Switch to 24-Hour");
}

void Clock::on_alarmButton_clicked()
{
    QMessageBox::information(this, "Alarm Feature", "Alarm functionality would be implemented here.");
}

void Clock::on_closeButton_clicked()
{
    accept();
}

void Clock::updateSystemResources()
{
    // Allocate memory for this application (if not already allocated)
    static bool memoryAllocated = false;
    if (!memoryAllocated) {
        SharedMemory::instance().allocateMemory(1);
        memoryAllocated = true;
    }
    
    // Update resource info
    ui->resourceLabel->setText(QString("Memory Usage: 1 MB | Process ID: %1").arg(qrand() % 1000 + 6000));
}