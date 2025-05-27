#include "maindashboard.h"
#include "ui_maindashboard.h"
#include <QTimer>
#include <QMessageBox>
#include <QIcon>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>

MainDashboard::MainDashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDashboard),
    nextAppId(1)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Dashboard");
    setFixedSize(800, 600);
    
    // Set up icons for application buttons
    ui->textEditorButton->setIcon(QIcon(":/icons/text-editor.png"));
    ui->textEditorButton->setIconSize(QSize(64, 64));
    
    ui->calculatorButton->setIcon(QIcon(":/icons/calculator.png"));
    ui->calculatorButton->setIconSize(QSize(64, 64));
    
    ui->resourcesButton->setIcon(QIcon(":/icons/resources.png"));
    ui->resourcesButton->setIconSize(QSize(64, 64));
    
    ui->gamesButton->setIcon(QIcon(":/icons/games.png"));
    ui->gamesButton->setIconSize(QSize(64, 64));
    
    // Create and set up the new application buttons
    QGridLayout *gridLayout = qobject_cast<QGridLayout*>(ui->centralwidget->layout()->itemAt(3)->layout());
    
    // Calendar button
    QPushButton *calendarButton = new QPushButton("Calendar", this);
    calendarButton->setObjectName("calendarButton");
    calendarButton->setMinimumSize(150, 150);
    calendarButton->setIcon(QIcon(":/icons/calendar.png"));
    calendarButton->setIconSize(QSize(64, 64));
    QFont buttonFont("Arial", 12, QFont::Bold);
    calendarButton->setFont(buttonFont);
    gridLayout->addWidget(calendarButton, 0, 2);
    connect(calendarButton, &QPushButton::clicked, this, &MainDashboard::on_calendarButton_clicked);
    
    // Clock button
    QPushButton *clockButton = new QPushButton("Clock", this);
    clockButton->setObjectName("clockButton");
    clockButton->setMinimumSize(150, 150);
    clockButton->setIcon(QIcon(":/icons/clock.png"));
    clockButton->setIconSize(QSize(64, 64));
    clockButton->setFont(buttonFont);
    gridLayout->addWidget(clockButton, 0, 3);
    connect(clockButton, &QPushButton::clicked, this, &MainDashboard::on_clockButton_clicked);
    
    // System Info button
    QPushButton *systeminfoButton = new QPushButton("System Info", this);
    systeminfoButton->setObjectName("systeminfoButton");
    systeminfoButton->setMinimumSize(150, 150);
    systeminfoButton->setIcon(QIcon(":/icons/systeminfo.png"));
    systeminfoButton->setIconSize(QSize(64, 64));
    systeminfoButton->setFont(buttonFont);
    gridLayout->addWidget(systeminfoButton, 1, 2);
    connect(systeminfoButton, &QPushButton::clicked, this, &MainDashboard::on_systeminfoButton_clicked);
    
    // PCB Table button
    QPushButton *pcbtableButton = new QPushButton("PCB Table", this);
    pcbtableButton->setObjectName("pcbtableButton");
    pcbtableButton->setMinimumSize(150, 150);
    pcbtableButton->setIcon(QIcon(":/icons/pcbtable.png"));
    pcbtableButton->setIconSize(QSize(64, 64));
    pcbtableButton->setFont(buttonFont);
    gridLayout->addWidget(pcbtableButton, 1, 3);
    connect(pcbtableButton, &QPushButton::clicked, this, &MainDashboard::on_pcbtableButton_clicked);
    
    // File Browser button
    QPushButton *filebrowserButton = new QPushButton("File Browser", this);
    filebrowserButton->setObjectName("filebrowserButton");
    filebrowserButton->setMinimumSize(150, 150);
    filebrowserButton->setIcon(QIcon(":/icons/filebrowser.png"));
    filebrowserButton->setIconSize(QSize(64, 64));
    filebrowserButton->setFont(buttonFont);
    gridLayout->addWidget(filebrowserButton, 2, 0);
    connect(filebrowserButton, &QPushButton::clicked, this, &MainDashboard::on_filebrowserButton_clicked);
    
    // Update memory display every second
    memoryUpdateTimer = new QTimer(this);
    connect(memoryUpdateTimer, &QTimer::timeout, this, &MainDashboard::updateMemoryLabel);
    memoryUpdateTimer->start(1000);
    
    // Initial update of memory label
    updateMemoryLabel();
    
    // Setup a timer to clean up closed applications
    QTimer *cleanupTimer = new QTimer(this);
    connect(cleanupTimer, &QTimer::timeout, this, &MainDashboard::removeClosedApps);
    cleanupTimer->start(500); // Check every 500ms
}

MainDashboard::~MainDashboard()
{
    // Clean up any running applications
    for(auto app : runningApps.values()) {
        if(app) {
            app->close();
            delete app;
        }
    }
    runningApps.clear();
    
    delete ui;
}

void MainDashboard::updateMemoryLabel()
{
    int availableMemory = SharedMemory::instance().getAvailableMemory();
    int totalMemory = SharedMemory::instance().getTotalMemory();
    int diskSpace = SharedMemory::instance().getDiskSpace();
    int cpuCores = SharedMemory::instance().getCpuCores();
    
    // Also show the number of running apps in the status bar
    ui->memoryLabel->setText(QString("Memory: %1/%2 MB | Disk: %3 MB | CPU: %4 cores | Running Apps: %5")
                            .arg(availableMemory)
                            .arg(totalMemory)
                            .arg(diskSpace)
                            .arg(cpuCores)
                            .arg(runningApps.size()));
}

void MainDashboard::on_textEditorButton_clicked()
{
    TextEditor* textEditor = new TextEditor(nullptr);
    launchApp(textEditor, "Text Editor");
}

void MainDashboard::on_calculatorButton_clicked()
{
    Calculator* calculator = new Calculator(nullptr);
    launchApp(calculator, "Calculator");
}

void MainDashboard::on_resourcesButton_clicked()
{
    MemoryStatus* memoryStatus = new MemoryStatus(nullptr);
    launchApp(memoryStatus, "Resource Monitor");
}

void MainDashboard::on_gamesButton_clicked()
{
    MiniGames* miniGames = new MiniGames(nullptr);
    launchApp(miniGames, "Mini Games");
}

void MainDashboard::on_calendarButton_clicked()
{
    Calendar* calendar = new Calendar(nullptr);
    launchApp(calendar, "Calendar");
}

void MainDashboard::on_clockButton_clicked()
{
    Clock* clock = new Clock(nullptr);
    launchApp(clock, "Clock");
}

void MainDashboard::on_systeminfoButton_clicked()
{
    SystemInfo* systemInfo = new SystemInfo(nullptr);
    launchApp(systemInfo, "System Info");
}

void MainDashboard::on_pcbtableButton_clicked()
{
    PCBTable* pcbTable = new PCBTable(nullptr);
    launchApp(pcbTable, "PCB Table");
}

void MainDashboard::on_filebrowserButton_clicked()
{
    FileBrowser* fileBrowser = new FileBrowser(nullptr);
    launchApp(fileBrowser, "File Browser");
}

void MainDashboard::launchApp(QDialog* app, const QString& appName)
{
    if (!app) {
        qDebug() << "Failed to create app:" << appName;
        return;
    }
    
    // Set window title to include app ID
    int appId = nextAppId++;
    app->setWindowTitle(QString("%1 [%2]").arg(appName).arg(appId));
    
    // Make non-modal so it doesn't block the main dashboard
    app->setModal(false);
    
    // Track the dialog in our running apps
    runningApps[appId] = app;
    
    // Handle dialog closure
    connect(app, &QDialog::finished, this, &MainDashboard::onAppClosed);
    
    // Show the dialog
    app->show();
    
    qDebug() << "Launched app" << appName << "with ID" << appId;
}

void MainDashboard::onAppClosed()
{
    // The actual cleanup happens in removeClosedApps
    // This is just a slot to catch the signal
}

void MainDashboard::removeClosedApps()
{
    QList<int> appsToRemove;
    
    // Find apps that are no longer visible
    for (auto it = runningApps.begin(); it != runningApps.end(); ++it) {
        if (!it.value() || !it.value()->isVisible()) {
            appsToRemove.append(it.key());
        }
    }
    
    // Remove closed apps
    for (int appId : appsToRemove) {
        QDialog* app = runningApps.take(appId);
        if (app) {
            delete app;
        }
        qDebug() << "Removed closed app with ID" << appId;
    }
    
    if (!appsToRemove.isEmpty()) {
        // Update memory label if apps were removed
        updateMemoryLabel();
    }
}
