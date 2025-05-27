#include "texteditor.h"
#include "ui_texteditor.h"
#include <QFile>
#include <QTextStream>

TextEditor::TextEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Text Editor");
    setFixedSize(700, 500);
    
    // Check if there's enough memory to run the text editor
    if (!checkMemoryAvailable(400)) {
        QMessageBox::warning(this, "Insufficient Resources", 
                            "Not enough memory available to launch Text Editor.\n"
                            "Required: 400 MB\n"
                            "Available: " + QString::number(SharedMemory::instance().getAvailableMemory()) + " MB");
        reject();
        return;
    }
    
    // Allocate memory for running the text editor
    SharedMemory::instance().allocateMemory(400);
}

TextEditor::~TextEditor()
{
    // Release memory when text editor is closed
    SharedMemory::instance().releaseMemory(400);
    delete ui;
}

bool TextEditor::checkMemoryAvailable(int requiredMemory)
{
    return SharedMemory::instance().getAvailableMemory() >= requiredMemory;
}

void TextEditor::on_createButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Create New File", "", "Text Files (*.txt);;All Files (*)");
    
    if (fileName.isEmpty())
        return;
    
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot create the file: " + file.errorString());
        return;
    }
    
    file.close();
    
    // Open the newly created file in the text editor
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->textEdit->setText(QString::fromUtf8(file.readAll()));
        ui->fileNameEdit->setText(fileName);
        file.close();
    }
    
    QMessageBox::information(this, "Success", "File created successfully: " + fileName);
}

void TextEditor::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    
    if (fileName.isEmpty())
        return;
    
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot open the file: " + file.errorString());
        return;
    }
    
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    ui->fileNameEdit->setText(fileName);
    file.close();
}

void TextEditor::on_saveButton_clicked()
{
    QString fileName = ui->fileNameEdit->text();
    
    if (fileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
        
        if (fileName.isEmpty())
            return;
            
        ui->fileNameEdit->setText(fileName);
    }
    
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot save the file: " + file.errorString());
        return;
    }
    
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    
    QMessageBox::information(this, "Success", "File saved successfully: " + fileName);
}

void TextEditor::on_closeButton_clicked()
{
    // Check if there are unsaved changes
    if (!ui->textEdit->document()->isModified() || 
        QMessageBox::question(this, "Unsaved Changes", 
                            "There are unsaved changes. Do you want to save before closing?", 
                            QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
        accept();
    } else {
        on_saveButton_clicked();
        if (!ui->textEdit->document()->isModified()) {
            accept();
        }
    }
}
