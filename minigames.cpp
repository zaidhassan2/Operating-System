#include "minigames.h"
#include "ui_minigames.h"
#include "bingogame.h"
#include <QGridLayout>
#include <QRandomGenerator>

MiniGames::MiniGames(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MiniGames),
    isPlayerX(true),
    gameActive(false)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - Mini Games");
    setFixedSize(600, 500);
    
    // Check if there's enough memory to run games
    if (!checkMemoryAvailable(200)) {
        QMessageBox::warning(this, "Insufficient Resources", 
                            "Not enough memory available to launch Mini Games.\n"
                            "Required: 200 MB\n"
                            "Available: " + QString::number(SharedMemory::instance().getAvailableMemory()) + " MB");
        reject();
        return;
    }
    
    // Allocate memory for running games
    SharedMemory::instance().allocateMemory(200);
}

MiniGames::~MiniGames()
{
    // Release memory when closing games
    SharedMemory::instance().releaseMemory(200);
    delete ui;
}

bool MiniGames::checkMemoryAvailable(int requiredMemory)
{
    return SharedMemory::instance().getAvailableMemory() >= requiredMemory;
}

void MiniGames::on_ticTacToeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Switch to Tic Tac Toe page
    setupTicTacToeGame();
}

void MiniGames::on_bingoButton_clicked()
{
    // Instead of using the stackedWidget, create a separate Bingo game dialog
    // and handle possible exceptions during creation
    try {
        // Check if we have enough memory for the Bingo game
        if (!checkMemoryAvailable(500)) { // Reduced from 2000 to 500
            QMessageBox::warning(this, "Insufficient Resources", 
                                "Not enough memory available to launch Bingo Game.\n"
                                "Required: 500 MB\n"
                                "Available: " + QString::number(SharedMemory::instance().getAvailableMemory()) + " MB");
            return;
        }
        
        BingoGame* bingoGame = new BingoGame(this);
        if (bingoGame) {
            bingoGame->exec();
            delete bingoGame;
        }
    } catch (...) {
        QMessageBox::critical(this, "Error", "Failed to start Bingo game. Please try again.");
    }
}

void MiniGames::on_closeButton_clicked()
{
    accept();
}

void MiniGames::setupTicTacToeGame()
{
    if (!gameActive) {
        // Clear previous game if any
        QLayoutItem *child;
        while ((child = ui->ticTacToeLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        
        // Create new game board
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                ticTacToeButtons[row][col] = new QPushButton(this);
                ticTacToeButtons[row][col]->setFixedSize(80, 80);
                ticTacToeButtons[row][col]->setFont(QFont("Arial", 24, QFont::Bold));
                ui->ticTacToeLayout->addWidget(ticTacToeButtons[row][col], row, col);
                
                // Connect the button to the handler
                connect(ticTacToeButtons[row][col], &QPushButton::clicked, this, &MiniGames::handleTicTacToeButtonClick);
            }
        }
        
        gameActive = true;
        isPlayerX = true;
        ui->gameStatusLabel->setText("Tic Tac Toe - Player X's turn");
    }
}

void MiniGames::handleTicTacToeButtonClick()
{
    if (!gameActive)
        return;
        
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button->text().isEmpty()) {
        button->setText(isPlayerX ? "X" : "O");
        
        if (checkTicTacToeWin()) {
            ui->gameStatusLabel->setText(QString("Player %1 wins!").arg(isPlayerX ? "X" : "O"));
            gameActive = false;
            
            QMessageBox::information(this, "Game Over", 
                QString("Player %1 wins!").arg(isPlayerX ? "X" : "O"));
                
            resetTicTacToeGame();
        } else {
            // Check for a draw
            bool isDraw = true;
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (ticTacToeButtons[row][col]->text().isEmpty()) {
                        isDraw = false;
                        break;
                    }
                }
                if (!isDraw) break;
            }
            
            if (isDraw) {
                ui->gameStatusLabel->setText("Game ended in a draw!");
                gameActive = false;
                
                QMessageBox::information(this, "Game Over", "Game ended in a draw!");
                
                resetTicTacToeGame();
            } else {
                isPlayerX = !isPlayerX;
                ui->gameStatusLabel->setText(QString("Player %1's turn").arg(isPlayerX ? "X" : "O"));
            }
        }
    }
}

bool MiniGames::checkTicTacToeWin()
{
    QString symbol = isPlayerX ? "X" : "O";
    
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (!ticTacToeButtons[row][0]->text().isEmpty() &&
            ticTacToeButtons[row][0]->text() == ticTacToeButtons[row][1]->text() &&
            ticTacToeButtons[row][1]->text() == ticTacToeButtons[row][2]->text()) {
            return true;
        }
    }
    
    // Check columns
    for (int col = 0; col < 3; col++) {
        if (!ticTacToeButtons[0][col]->text().isEmpty() &&
            ticTacToeButtons[0][col]->text() == ticTacToeButtons[1][col]->text() &&
            ticTacToeButtons[1][col]->text() == ticTacToeButtons[2][col]->text()) {
            return true;
        }
    }
    
    // Check diagonals
    if (!ticTacToeButtons[0][0]->text().isEmpty() &&
        ticTacToeButtons[0][0]->text() == ticTacToeButtons[1][1]->text() &&
        ticTacToeButtons[1][1]->text() == ticTacToeButtons[2][2]->text()) {
        return true;
    }
    
    if (!ticTacToeButtons[0][2]->text().isEmpty() &&
        ticTacToeButtons[0][2]->text() == ticTacToeButtons[1][1]->text() &&
        ticTacToeButtons[1][1]->text() == ticTacToeButtons[2][0]->text()) {
        return true;
    }
    
    return false;
}

void MiniGames::resetTicTacToeGame()
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            ticTacToeButtons[row][col]->setText("");
        }
    }
    
    gameActive = true;
    isPlayerX = true;
    ui->gameStatusLabel->setText("Tic Tac Toe - Player X's turn");
}
