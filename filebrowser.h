#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QDialog>
#include <QTimer>
#include <QFileSystemModel>
#include <QListWidgetItem>
#include <QVector>
#include "sharedmemory.h"

// Define a struct to represent a virtual file entry
struct FileEntry {
    QString name;
    QString path;
    QString type; // "file" or "directory"
    int size;
    QString created;
    QString modified;
    QString permissions;
};

namespace Ui {
class FileBrowser;
}

class FileBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit FileBrowser(QWidget *parent = nullptr);
    ~FileBrowser();

private slots:
    void on_backButton_clicked();
    void on_homeButton_clicked();
    void on_refreshButton_clicked();
    void on_createButton_clicked();
    void on_deleteButton_clicked();
    void on_closeButton_clicked();
    void updateSystemResources();
    void onFileDoubleClicked(QListWidgetItem *item);

private:
    Ui::FileBrowser *ui;
    QTimer *resourceTimer;
    QVector<FileEntry> currentDirContents;
    QString currentPath;
    QVector<QString> pathHistory;
    
    void refreshFileList();
    void navigateToDirectory(const QString &path);
    void generateVirtualFileSystem();
    void createVirtualDirectory(const QString &dirName);
    void createVirtualFile(const QString &fileName);
    void deleteVirtualEntry(const QString &name);
};

#endif // FILEBROWSER_H