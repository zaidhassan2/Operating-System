#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculator),
    firstOperand(0),
    secondOperand(0),
    waitingForOperand(false),
    resetDisplay(false)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Calculator");
    
    // Check if there's enough memory to run calculator
    if (!checkMemoryAvailable(200)) {
        QMessageBox::warning(this, "Insufficient Resources", 
                            "Not enough memory available to launch Calculator.\n"
                            "Required: 200 MB\n"
                            "Available: " + QString::number(SharedMemory::instance().getAvailableMemory()) + " MB");
        reject();
        return;
    }
    
    // Allocate memory for running calculator
    SharedMemory::instance().allocateMemory(200);
    
    // Connect digit buttons
    connect
    
    (ui->button0, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button1, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button2, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button3, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button4, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button5, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button6, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button7, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button8, &QPushButton::clicked, this, &Calculator::digitPressed);
    connect(ui->button9, &QPushButton::clicked, this, &Calculator::digitPressed);
    
    // Connect operation buttons
    connect(ui->buttonPlus, &QPushButton::clicked, this, &Calculator::operationPressed);
    connect(ui->buttonMinus, &QPushButton::clicked, this, &Calculator::operationPressed);
    connect(ui->buttonMultiply, &QPushButton::clicked, this, &Calculator::operationPressed);
    connect(ui->buttonDivide, &QPushButton::clicked, this, &Calculator::operationPressed);
    
    // Connect equals and clear buttons
    connect(ui->buttonEquals, &QPushButton::clicked, this, &Calculator::equalsPressed);
    connect(ui->buttonClear, &QPushButton::clicked, this, &Calculator::clearPressed);
    
    // Initialize display
    ui->displayLineEdit->setText("0");
}

Calculator::~Calculator()
{
    // Release memory when calculator is closed
    SharedMemory::instance().releaseMemory(200);
    delete ui;
}

bool Calculator::checkMemoryAvailable(int requiredMemory)
{
    return SharedMemory::instance().getAvailableMemory() >= requiredMemory;
}

void Calculator::digitPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonValue = button->text();
    
    if (ui->displayLineEdit->text() == "0" || resetDisplay) {
        ui->displayLineEdit->setText(buttonValue);
        resetDisplay = false;
    } else {
        ui->displayLineEdit->setText(ui->displayLineEdit->text() + buttonValue);
    }
}

void Calculator::operationPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    
    firstOperand = ui->displayLineEdit->text().toDouble();
    
    operation = button->text();
    resetDisplay = true;
}

void Calculator::equalsPressed()
{
    double secondOperand = ui->displayLineEdit->text().toDouble();
    double result = 0;
    
    if (operation == "+") {
        result = firstOperand + secondOperand;
    } else if (operation == "-") {
        result = firstOperand - secondOperand;
    } else if (operation == "*") {
        result = firstOperand * secondOperand;
    } else if (operation == "/") {
        if (secondOperand != 0) {
            result = firstOperand / secondOperand;
        } else {
            QMessageBox::warning(this, "Error", "Cannot divide by zero!");
            ui->displayLineEdit->setText("Error");
            resetDisplay = true;
            return;
        }
    }
    
    ui->displayLineEdit->setText(QString::number(result));
    resetDisplay = true;
}

void Calculator::clearPressed()
{
    ui->displayLineEdit->setText("0");
    resetDisplay = true;
    firstOperand = 0;
    operation = "";
}

void Calculator::decimalPressed()
{
    if (!ui->displayLineEdit->text().contains('.')) {
        ui->displayLineEdit->setText(ui->displayLineEdit->text() + ".");
    }
}

void Calculator::on_closeButton_clicked()
{
    accept();
}
