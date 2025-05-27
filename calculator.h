#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include "sharedmemory.h"

namespace Ui {
class Calculator;
}

class Calculator : public QDialog
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void digitPressed();
    void operationPressed();
    void equalsPressed();
    void clearPressed();
    void decimalPressed();
    void on_closeButton_clicked();

private:
    Ui::Calculator *ui;
    double firstOperand;
    double secondOperand;
    QString currentOperation;
    bool waitingForOperand;
    bool resetDisplay;
    QString operation;
    bool checkMemoryAvailable(int requiredMemory);
};

#endif // CALCULATOR_H
