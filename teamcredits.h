#ifndef TEAMCREDITS_H
#define TEAMCREDITS_H


#include <QDialog>
#include <QPushButton>

class QLabel;
class QVBoxLayout;

class TeamCredits : public QDialog
{
    Q_OBJECT

public:
    explicit TeamCredits(QWidget *parent = nullptr);
    ~TeamCredits();

private:
    QPushButton *continueButton;
    QLabel *titleLabel;
    QLabel *creditsLabel;
};

#endif // TEAMCREDITS_H
