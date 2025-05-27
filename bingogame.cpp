#include "bingogame.h"
#include <QDebug>
#include <QDateTime>

BingoGame::BingoGame(QWidget *parent) 
    : QDialog(parent), 
      currentPlayer(0),
      totalScore1(0),
      totalScore2(0), 
      gameStarted(false)
{
    setWindowTitle("Mini OS - Bingo Game");
    setFixedSize(800, 600);
    
    // Create a private random generator instead of using global()
    // This is the key fix - creating our own generator instead of trying to modify the global one
    qint64 seed = QDateTime::currentMSecsSinceEpoch();
    randomGenerator = QRandomGenerator(static_cast<quint32>(seed));
    
    // Create game IDs using our private generator
    gameID1 = randomGenerator.bounded(10000, 99999);
    gameID2 = randomGenerator.bounded(10000, 99999);
    
    setupUI();
    
    // Resource allocation check - reduce required memory from 2000 to 500
    int availableMemory = SharedMemory::instance().getAvailableMemory();
    qDebug() << "Available memory: " << availableMemory;
    
    if (availableMemory < 500) {
        QMessageBox::warning(this, "Resource Warning", 
                            "Bingo game requires 500MB of memory.\n"
                            "Available memory: " + QString::number(availableMemory) + "MB\n"
                            "Game performance may be affected.");
    } else {
        // Allocate memory - reduced from 2000 to 500
        SharedMemory::instance().allocateMemory(500);
    }
}

BingoGame::~BingoGame()
{
    // Free allocated memory when the game closes
    try {
        if (gameStarted) {
            // Reduced from 2000 to 500
            SharedMemory::instance().releaseMemory(500);
        }
    } catch (...) {
        // Suppress any exceptions in the destructor
        qDebug() << "Error releasing memory in BingoGame destructor";
    }
}

void BingoGame::setupUI()
{
    mainLayout = new QVBoxLayout(this);
    
    // Player name inputs
    QHBoxLayout *nameLayout = new QHBoxLayout();
    player1NameEdit = new QLineEdit(this);
    player2NameEdit = new QLineEdit(this);
    player1NameEdit->setPlaceholderText("Enter Player 1 Name");
    player2NameEdit->setPlaceholderText("Enter Player 2 Name");
    
    nameLayout->addWidget(new QLabel("Player 1:"));
    nameLayout->addWidget(player1NameEdit);
    nameLayout->addWidget(new QLabel("Player 2:"));
    nameLayout->addWidget(player2NameEdit);
    
    mainLayout->addLayout(nameLayout);
    
    // Game board layout
    gameLayout = new QHBoxLayout();
    
    // Player 1 board
    QVBoxLayout *p1Layout = new QVBoxLayout();
    player1Label = new QLabel("Player 1");
    player1Label->setAlignment(Qt::AlignCenter);
    QFont labelFont = player1Label->font();
    labelFont.setPointSize(14);
    labelFont.setBold(true);
    player1Label->setFont(labelFont);
    
    scoreLabel1 = new QLabel("Score: 0");
    scoreLabel1->setAlignment(Qt::AlignCenter);
    
    gameIDLabel1 = new QLabel("Game ID: " + QString::number(gameID1));
    gameIDLabel1->setAlignment(Qt::AlignCenter);
    
    player1Layout = new QGridLayout();
    
    p1Layout->addWidget(player1Label);
    p1Layout->addWidget(scoreLabel1);
    p1Layout->addWidget(gameIDLabel1);
    p1Layout->addLayout(player1Layout);
    
    // Player 2 board
    QVBoxLayout *p2Layout = new QVBoxLayout();
    player2Label = new QLabel("Player 2");
    player2Label->setAlignment(Qt::AlignCenter);
    player2Label->setFont(labelFont);
    
    scoreLabel2 = new QLabel("Score: 0");
    scoreLabel2->setAlignment(Qt::AlignCenter);
    
    gameIDLabel2 = new QLabel("Game ID: " + QString::number(gameID2));
    gameIDLabel2->setAlignment(Qt::AlignCenter);
    
    player2Layout = new QGridLayout();
    
    p2Layout->addWidget(player2Label);
    p2Layout->addWidget(scoreLabel2);
    p2Layout->addWidget(gameIDLabel2);
    p2Layout->addLayout(player2Layout);
    
    // Initialize buttons for both boards
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Player 1 buttons
            player1Buttons[i][j] = new QPushButton(this);
            player1Buttons[i][j]->setFixedSize(50, 50);
            player1Buttons[i][j]->setProperty("row", i);
            player1Buttons[i][j]->setProperty("col", j);
            player1Buttons[i][j]->setProperty("player", 1);
            player1Layout->addWidget(player1Buttons[i][j], i, j);
            
            connect(player1Buttons[i][j], &QPushButton::clicked, this, &BingoGame::onCellClicked);
            
            // Player 2 buttons
            player2Buttons[i][j] = new QPushButton(this);
            player2Buttons[i][j]->setFixedSize(50, 50);
            player2Buttons[i][j]->setProperty("row", i);
            player2Buttons[i][j]->setProperty("col", j);
            player2Buttons[i][j]->setProperty("player", 2);
            player2Layout->addWidget(player2Buttons[i][j], i, j);
            
            connect(player2Buttons[i][j], &QPushButton::clicked, this, &BingoGame::onCellClicked);
        }
    }
    
    gameLayout->addLayout(p1Layout);
    gameLayout->addLayout(p2Layout);
    mainLayout->addLayout(gameLayout);
    
    // Turn indicator
    turnLabel = new QLabel("Press Start to begin the game");
    turnLabel->setAlignment(Qt::AlignCenter);
    labelFont.setPointSize(16);
    turnLabel->setFont(labelFont);
    turnLabel->setStyleSheet("color: red;");
    mainLayout->addWidget(turnLabel);
    
    // Control buttons
    controlLayout = new QHBoxLayout();
    startButton = new QPushButton("Start Game", this);
    exitButton = new QPushButton("Exit", this);
    
    connect(startButton, &QPushButton::clicked, this, &BingoGame::startGame);
    connect(exitButton, &QPushButton::clicked, this, &BingoGame::exitGame);
    
    controlLayout->addWidget(startButton);
    controlLayout->addWidget(exitButton);
    mainLayout->addLayout(controlLayout);
    
    // Initially disable all cells until game starts
    disableAllCells();
}

void BingoGame::initializeBoard()
{
    // Clear and initialize player boards
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            player1Board[i][j] = 0;
            player2Board[i][j] = 0;
        }
    }
    
    // Generate random numbers for player 1 board
    QList<int> usedNumbers;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            do {
                num = randomGenerator.bounded(1, 26); // 1-25
            } while (usedNumbers.contains(num));
            
            usedNumbers.append(num);
            player1Board[i][j] = num;
            player1Buttons[i][j]->setText(QString::number(num));
        }
    }
    
    // Generate random numbers for player 2 board
    usedNumbers.clear();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            do {
                num = randomGenerator.bounded(1, 26); // 1-25
            } while (usedNumbers.contains(num));
            
            usedNumbers.append(num);
            player2Board[i][j] = num;
            player2Buttons[i][j]->setText(QString::number(num));
        }
    }
}

void BingoGame::startGame()
{
    // Check if player names are provided
    player1Name = player1NameEdit->text().trimmed();
    player2Name = player2NameEdit->text().trimmed();
    
    if (player1Name.isEmpty()) {
        player1Name = "Player 1";
    }
    if (player2Name.isEmpty()) {
        player2Name = "Player 2";
    }
    
    player1Label->setText(player1Name);
    player2Label->setText(player2Name);
    
    // Initialize the game
    initializeBoard();
    gameStarted = true;
    
    // Save player names to game details file - with proper error handling
    try {
        QFile file("GameDetails.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream stream(&file);
            stream << "Player 1 Name is " << player1Name << "\n";
            stream << "Player 2 Name is " << player2Name << "\n\n";
            file.close();
        } else {
            qDebug() << "Failed to open GameDetails.txt for writing";
            // Don't show an error message to the user - just log it
        }
    } catch (const std::exception& e) {
        qDebug() << "Exception when writing to GameDetails.txt:" << e.what();
    } catch (...) {
        qDebug() << "Unknown exception when writing to GameDetails.txt";
    }
    
    // Determine who goes first (random)
    currentPlayer = randomGenerator.bounded(2) + 1; // 1 or 2
    
    if (currentPlayer == 1) {
        turnLabel->setText(player1Name + "'s Turn");
        enablePlayerCells(1);
        disablePlayerCells(2);
    } else {
        turnLabel->setText(player2Name + "'s Turn");
        enablePlayerCells(2);
        disablePlayerCells(1);
    }
    
    // Disable start button after game starts
    startButton->setEnabled(false);
}

void BingoGame::onCellClicked()
{
    if (!gameStarted) return;
    
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    int player = button->property("player").toInt();
    
    if (player != currentPlayer) return;
    
    int number = button->text().toInt();
    
    // Mark the number on both boards
    markNumber(number);
    
    // Check for win
    checkWin();
    
    // Switch turns
    nextPlayerTurn();
}

void BingoGame::markNumber(int number)
{
    // Mark on player 1's board
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (player1Board[i][j] == number) {
                player1Board[i][j] = 0;
                player1Buttons[i][j]->setText("X");
                player1Buttons[i][j]->setStyleSheet("background-color: #ffaaaa;");
            }
        }
    }
    
    // Mark on player 2's board
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (player2Board[i][j] == number) {
                player2Board[i][j] = 0;
                player2Buttons[i][j]->setText("X");
                player2Buttons[i][j]->setStyleSheet("background-color: #ffaaaa;");
            }
        }
    }
    
    // Update scores
    updateScores();
}

void BingoGame::nextPlayerTurn()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    
    if (currentPlayer == 1) {
        turnLabel->setText(player1Name + "'s Turn");
        enablePlayerCells(1);
        disablePlayerCells(2);
    } else {
        turnLabel->setText(player2Name + "'s Turn");
        enablePlayerCells(2);
        disablePlayerCells(1);
    }
}

void BingoGame::checkWin()
{
    bool player1Win = checkBingo(player1Buttons);
    bool player2Win = checkBingo(player2Buttons);
    
    if (player1Win || player2Win) {
        disableAllCells();
        
        QString winner;
        int score;
        
        if (player1Win) {
            winner = player1Name;
            score = totalScore1;
        } else {
            winner = player2Name;
            score = totalScore2;
        }
        
        // Save score to file with proper error handling
        try {
            QFile file("ScoreDetail.txt");
            if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
                QTextStream stream(&file);
                stream << winner << "'s Score is " << score << "\n";
                file.close();
            } else {
                qDebug() << "Failed to open ScoreDetail.txt for writing";
                // Don't show an error message to the user - just log it
            }
        } catch (const std::exception& e) {
            qDebug() << "Exception when writing to ScoreDetail.txt:" << e.what();
        } catch (...) {
            qDebug() << "Unknown exception when writing to ScoreDetail.txt";
        }
        
        QMessageBox::information(this, "Game Over", 
                                winner + " won the game!\nScore: " + QString::number(score));
        
        // Allow starting a new game
        startButton->setEnabled(true);
        gameStarted = false;
    }
}

bool BingoGame::checkBingo(QPushButton* buttons[5][5])
{
    int count = 0;
    
    // Check rows
    for (int i = 0; i < 5; i++) {
        bool rowComplete = true;
        for (int j = 0; j < 5; j++) {
            if (buttons[i][j]->text() != "X") {
                rowComplete = false;
                break;
            }
        }
        if (rowComplete) count++;
    }
    
    // Check columns
    for (int j = 0; j < 5; j++) {
        bool colComplete = true;
        for (int i = 0; i < 5; i++) {
            if (buttons[i][j]->text() != "X") {
                colComplete = false;
                break;
            }
        }
        if (colComplete) count++;
    }
    
    // Check main diagonal
    bool diagComplete = true;
    for (int i = 0; i < 5; i++) {
        if (buttons[i][i]->text() != "X") {
            diagComplete = false;
            break;
        }
    }
    if (diagComplete) count++;
    
    // Check anti-diagonal
    bool antiDiagComplete = true;
    for (int i = 0; i < 5; i++) {
        if (buttons[i][4-i]->text() != "X") {
            antiDiagComplete = false;
            break;
        }
    }
    if (antiDiagComplete) count++;
    
    // Win if 5 or more lines completed
    return count >= 5;
}

int BingoGame::countScore(QPushButton* buttons[5][5])
{
    int count = 0;
    
    // Count completed rows
    for (int i = 0; i < 5; i++) {
        bool rowComplete = true;
        for (int j = 0; j < 5; j++) {
            if (buttons[i][j]->text() != "X") {
                rowComplete = false;
                break;
            }
        }
        if (rowComplete) count++;
    }
    
    // Count completed columns
    for (int j = 0; j < 5; j++) {
        bool colComplete = true;
        for (int i = 0; i < 5; i++) {
            if (buttons[i][j]->text() != "X") {
                colComplete = false;
                break;
            }
        }
        if (colComplete) count++;
    }
    
    // Check main diagonal
    bool diagComplete = true;
    for (int i = 0; i < 5; i++) {
        if (buttons[i][i]->text() != "X") {
            diagComplete = false;
            break;
        }
    }
    if (diagComplete) count++;
    
    // Check anti-diagonal
    bool antiDiagComplete = true;
    for (int i = 0; i < 5; i++) {
        if (buttons[i][4-i]->text() != "X") {
            antiDiagComplete = false;
            break;
        }
    }
    if (antiDiagComplete) count++;
    
    return count * 10; // 10 points per completed line
}

void BingoGame::updateScores()
{
    totalScore1 = countScore(player1Buttons);
    totalScore2 = countScore(player2Buttons);
    
    scoreLabel1->setText("Score: " + QString::number(totalScore1));
    scoreLabel2->setText("Score: " + QString::number(totalScore2));
}

void BingoGame::disableAllCells()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            player1Buttons[i][j]->setEnabled(false);
            player2Buttons[i][j]->setEnabled(false);
        }
    }
}

void BingoGame::enablePlayerCells(int playerNum)
{
    QPushButton* (*buttons)[5] = (playerNum == 1) ? player1Buttons : player2Buttons;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Only enable cells that haven't been marked yet
            if (buttons[i][j]->text() != "X") {
                buttons[i][j]->setEnabled(true);
            }
        }
    }
}

void BingoGame::disablePlayerCells(int playerNum)
{
    QPushButton* (*buttons)[5] = (playerNum == 1) ? player1Buttons : player2Buttons;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            buttons[i][j]->setEnabled(false);
        }
    }
}

void BingoGame::exitGame()
{
    try {
        if (gameStarted) {
            // Release allocated memory - reduced from 2000 to 500
            SharedMemory::instance().releaseMemory(500);
            gameStarted = false;
        }
        accept();
    } catch (const std::exception& e) {
        qDebug() << "Exception in exitGame:" << e.what();
        accept(); // Still exit even if there's an error
    } catch (...) {
        qDebug() << "Unknown exception in exitGame";
        accept(); // Still exit even if there's an error
    }
}
