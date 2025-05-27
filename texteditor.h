#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTabWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "sharedmemory.h"

namespace Ui {
class TextEditor;
}

class TextEditor : public QDialog
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    void on_createButton_clicked();
    void on_openButton_clicked();
    void on_saveButton_clicked();
    void on_closeButton_clicked();

private:
    Ui::TextEditor *ui;
    bool checkMemoryAvailable(int requiredMemory);
};

#endif // TEXTEDITOR_H
