#ifndef BINGOGAME_H
#define BINGOGAME_H


#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "sharedmemory.h"

class BingoGame : public QDialog
{
    Q_OBJECT

public:
    explicit BingoGame(QWidget *parent = nullptr);
    ~BingoGame();

private slots:
    void onCellClicked();
    void startGame();
    void checkWin();
    void nextPlayerTurn();
    void exitGame();
    
private:
    void setupUI();
    void initializeBoard();
    void updateScores();
    bool checkBingo(QPushButton* buttons[5][5]);
    int countScore(QPushButton* buttons[5][5]);
    void markNumber(int number);
    void disableAllCells();
    void enablePlayerCells(int playerNum);
    void disablePlayerCells(int playerNum);
    
    // Our own instance of QRandomGenerator
    QRandomGenerator randomGenerator;
    
    QGridLayout *player1Layout;
    QGridLayout *player2Layout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *gameLayout;
    QHBoxLayout *controlLayout;
    
    QPushButton *startButton;
    QPushButton *exitButton;
    
    QLineEdit *player1NameEdit;
    QLineEdit *player2NameEdit;
    
    QLabel *player1Label;
    QLabel *player2Label;
    QLabel *scoreLabel1;
    QLabel *scoreLabel2;
    QLabel *turnLabel;
    QLabel *gameIDLabel1;
    QLabel *gameIDLabel2;
    
    QPushButton *player1Buttons[5][5];
    QPushButton *player2Buttons[5][5];
    
    int player1Board[5][5];
    int player2Board[5][5];
    
    int currentPlayer;
    int gameID1;
    int gameID2;
    int totalScore1;
    int totalScore2;
    bool gameStarted;
    
    QString player1Name;
    QString player2Name;
};

#endif // BINGOGAME_H
