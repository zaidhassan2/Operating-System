#ifndef MODESELECTION_H
#define MODESELECTION_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ModeSelection;
}

class ModeSelection : public QDialog
{
    Q_OBJECT

public:
    explicit ModeSelection(QWidget *parent = nullptr);
    ~ModeSelection();

    bool isUserMode() const { return userMode; }

private slots:
    void on_kernelButton_clicked();
    void on_userButton_clicked();

private:
    Ui::ModeSelection *ui;
    bool userMode;
};

#endif // MODESELECTION_H
