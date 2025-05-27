#ifndef MINIGAMES_H
#define MINIGAMES_H

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include "sharedmemory.h"

namespace Ui {
class MiniGames;
}

class MiniGames : public QDialog
{
    Q_OBJECT

public:
    explicit MiniGames(QWidget *parent = nullptr);
    ~MiniGames();

private slots:
    void on_ticTacToeButton_clicked();
    void on_bingoButton_clicked();
    void on_closeButton_clicked();

private:
    Ui::MiniGames *ui;
    bool checkMemoryAvailable(int requiredMemory);
    
    // Tic Tac Toe game variables
    QPushButton *ticTacToeButtons[3][3];
    bool isPlayerX;
    bool gameActive;
    
    void setupTicTacToeGame();
    void handleTicTacToeButtonClick();
    bool checkTicTacToeWin();
    void resetTicTacToeGame();
};

#endif // MINIGAMES_H
