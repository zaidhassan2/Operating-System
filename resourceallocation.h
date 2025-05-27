#ifndef RESOURCEALLOCATION_H
#define RESOURCEALLOCATION_H

#include <QDialog>
#include "sharedmemory.h"

namespace Ui {
class ResourceAllocation;
}

class ResourceAllocation : public QDialog
{
    Q_OBJECT

public:
    explicit ResourceAllocation(QWidget *parent = nullptr);
    ~ResourceAllocation();

private slots:
    void on_allocateButton_clicked();

private:
    Ui::ResourceAllocation *ui;
};

#endif // RESOURCEALLOCATION_H
