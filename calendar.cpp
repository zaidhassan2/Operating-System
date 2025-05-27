#include "calendar.h"
#include "ui_calendar.h"
#include <QTimer>
#include <QMessageBox>

Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Calendar");
    setFixedSize(600, 500);
    
    // Set up timer to update system resources
    resourceTimer = new QTimer(this);
    connect(resourceTimer, &QTimer::timeout, this, &Calendar::updateSystemResources);
    resourceTimer->start(1000);
    
    // Initial update
    updateSystemResources();
    
    // Connect date selection signal
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &Calendar::on_dateSelected);
    connect(ui->closeButton, &QPushButton::clicked, this, &Calendar::on_closeButton_clicked);
}

Calendar::~Calendar()
{
    // Deduct memory usage when closing
    SharedMemory::instance().releaseMemory(2);
    delete ui;
}

void Calendar::on_dateSelected(const QDate &date)
{
    ui->selectedDateLabel->setText("Selected Date: " + date.toString("yyyy-MM-dd"));
    QMessageBox::information(this, "Date Selected", "You selected: " + date.toString("MMMM d, yyyy"));
}

void Calendar::on_closeButton_clicked()
{
    accept();
}

void Calendar::updateSystemResources()
{
    // Allocate memory for this application (if not already allocated)
    static bool memoryAllocated = false;
    if (!memoryAllocated) {
        SharedMemory::instance().allocateMemory(2);
        memoryAllocated = true;
    }
    
    // Update resource info
    ui->resourceLabel->setText(QString("Memory Usage: 2 MB | Process ID: %1").arg(qrand() % 1000 + 5000));
}