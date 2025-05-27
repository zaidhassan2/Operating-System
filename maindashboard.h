#ifndef MAINDASHBOARD_H
#define MAINDASHBOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QString>
#include <QDialog>
#include "sharedmemory.h"
#include "texteditor.h"
#include "calculator.h"
#include "memorystatus.h"
#include "minigames.h"
#include "calendar.h"
#include "clock.h"
#include "systeminfo.h"
#include "pcbtable.h"
#include "filebrowser.h"

namespace Ui {
class MainDashboard;
}

class MainDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDashboard(QWidget *parent = nullptr);
    ~MainDashboard();

private slots:
    void on_textEditorButton_clicked();
    void on_calculatorButton_clicked();
    void on_resourcesButton_clicked();
    void on_gamesButton_clicked();
    void updateMemoryLabel();
    void on_calendarButton_clicked();
    void on_clockButton_clicked();
    void on_systeminfoButton_clicked();
    void on_pcbtableButton_clicked();
    void on_filebrowserButton_clicked();
    void onAppClosed();

private:
    Ui::MainDashboard *ui;
    QTimer *memoryUpdateTimer;
    
    // Track running applications for multitasking
    QMap<int, QDialog*> runningApps;
    int nextAppId;
    
    // Helper method to launch applications
    void launchApp(QDialog* app, const QString& appName);
    
    // Clean up closed applications
    void removeClosedApps();
};

#endif // MAINDASHBOARD_H
