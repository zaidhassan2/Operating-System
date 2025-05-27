#include "teamcredits.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QDateTime>
#include <QFont>

TeamCredits::TeamCredits(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Mini OS - Team Credits");
    setFixedSize(600, 500);
    
    // Create a vertical layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    // Create title label
    titleLabel = new QLabel("Welcome to Our Mini OS", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont("Arial", 24, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: #FF0000;"); // Red color
    
    // Create credits content
    creditsLabel = new QLabel(this);
    creditsLabel->setAlignment(Qt::AlignCenter);
    QFont creditsFont("Arial", 14);
    creditsLabel->setFont(creditsFont);
    creditsLabel->setStyleSheet("color: #FF0000; background-color: #FFEEEE; padding: 20px; border: 2px solid #FF0000;");
    
    // Get current date and time
    QString currentDate = QDateTime::currentDateTime().toString("ddd MMM d yyyy");
    
    // Set the credits text with HTML formatting
    creditsLabel->setText(
        "<div style='text-align: center;'>"
        "<p style='font-size: 20px; font-weight: bold;'>********************************************</p>"
        "<p><b>Member 1: Zaid Hassan</b><br>"
        "Roll No.: 23F-3031</p>"
        "<p><b>Member 2: Hafiz Rizwan</b><br>"
        "Roll No.: 23F-3014</p>"
        "<p><b>Member 3: Hamza Ismail</b><br>"
        "Roll No.: 23F-3109</p>"
        "<p><b>Current Date: " + currentDate + "</b></p>"
        "<p style='font-size: 20px; font-weight: bold;'>********************************************</p>"
        "</div>"
    );
    
    // Create a button to continue
    continueButton = new QPushButton("Continue to OS", this);
    connect(continueButton, &QPushButton::clicked, this, &TeamCredits::accept);
    
    // Add widgets to layout
    layout->addWidget(titleLabel);
    layout->addWidget(creditsLabel);
    layout->addWidget(continueButton);
    
    // Set up auto-continue timer (5 seconds)
    QTimer::singleShot(5000, this, &TeamCredits::accept);
}

TeamCredits::~TeamCredits()
{
    // Qt will handle deleting the child widgets
}
