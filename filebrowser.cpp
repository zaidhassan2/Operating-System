#include "filebrowser.h"
#include "ui_filebrowser.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include <QRandomGenerator>

FileBrowser::FileBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);
    setWindowTitle("Mini OS - File Browser");
    setFixedSize(700, 500);
    
    // Set up timer to update system resources
    resourceTimer = new QTimer(this);
    connect(resourceTimer, &QTimer::timeout, this, &FileBrowser::updateSystemResources);
    resourceTimer->start(1000);
    
    // Set up file list connections
    connect(ui->fileListWidget, &QListWidget::itemDoubleClicked, this, &FileBrowser::onFileDoubleClicked);
    
    // Set up the initial file system
    currentPath = "/";
    generateVirtualFileSystem();
    navigateToDirectory("/");
    
    // Initial update of resources
    updateSystemResources();
}

FileBrowser::~FileBrowser()
{
    // Deduct memory usage when closing
    SharedMemory::instance().releaseMemory(3);
    delete ui;
}

void FileBrowser::updateSystemResources()
{
    // Allocate memory for this application (if not already allocated)
    static bool memoryAllocated = false;
    if (!memoryAllocated) {
        SharedMemory::instance().allocateMemory(3);
        memoryAllocated = true;
    }
    
    // Update resource info
    ui->resourceLabel->setText(QString("Memory Usage: 3 MB | Process ID: %1").arg(qrand() % 1000 + 9000));
}

void FileBrowser::generateVirtualFileSystem()
{
    currentDirContents.clear();
    
    // Generate the root directory contents
    
    // System directories
    FileEntry bin;
    bin.name = "bin";
    bin.path = "/bin";
    bin.type = "directory";
    bin.size = 0;
    bin.created = "System Boot";
    bin.modified = "System Boot";
    bin.permissions = "rwxr-xr-x";
    currentDirContents.append(bin);
    
    FileEntry etc;
    etc.name = "etc";
    etc.path = "/etc";
    etc.type = "directory";
    etc.size = 0;
    etc.created = "System Boot";
    etc.modified = "System Boot";
    etc.permissions = "rwxr-xr-x";
    currentDirContents.append(etc);
    
    FileEntry home;
    home.name = "home";
    home.path = "/home";
    home.type = "directory";
    home.size = 0;
    home.created = "System Boot";
    home.modified = "System Boot";
    home.permissions = "rwxr-xr-x";
    currentDirContents.append(home);
    
    FileEntry lib;
    lib.name = "lib";
    lib.path = "/lib";
    lib.type = "directory";
    lib.size = 0;
    lib.created = "System Boot";
    lib.modified = "System Boot";
    lib.permissions = "rwxr-xr-x";
    currentDirContents.append(lib);
    
    FileEntry usr;
    usr.name = "usr";
    usr.path = "/usr";
    usr.type = "directory";
    usr.size = 0;
    usr.created = "System Boot";
    usr.modified = "System Boot";
    usr.permissions = "rwxr-xr-x";
    currentDirContents.append(usr);
    
    // System files
    FileEntry passwd;
    passwd.name = "passwd";
    passwd.path = "/etc/passwd";
    passwd.type = "file";
    passwd.size = 1024;
    passwd.created = "System Boot";
    passwd.modified = "System Boot";
    passwd.permissions = "rw-r--r--";
    
    FileEntry fstab;
    fstab.name = "fstab";
    fstab.path = "/etc/fstab";
    fstab.type = "file";
    fstab.size = 512;
    fstab.created = "System Boot";
    fstab.modified = "System Boot";
    fstab.permissions = "rw-r--r--";
    
    // User files
    FileEntry readme;
    readme.name = "readme.txt";
    readme.path = "/home/readme.txt";
    readme.type = "file";
    readme.size = 2048;
    readme.created = "2024-05-10 10:30:00";
    readme.modified = "2024-05-10 10:30:00";
    readme.permissions = "rw-r--r--";
    
    FileEntry document;
    document.name = "document.txt";
    document.path = "/home/document.txt";
    document.type = "file";
    document.size = 4096;
    document.created = "2024-05-10 11:15:00";
    document.modified = "2024-05-10 12:30:00";
    document.permissions = "rw-------";
}

void FileBrowser::navigateToDirectory(const QString &path)
{
    // Store current path in history for back button
    if (currentPath != path) {
        pathHistory.append(currentPath);
    }
    
    currentPath = path;
    ui->pathLabel->setText("Location: " + currentPath);
    
    // Clear the current list
    currentDirContents.clear();
    
    // Handle root directory
    if (path == "/") {
        // System directories
        FileEntry bin;
        bin.name = "bin";
        bin.path = "/bin";
        bin.type = "directory";
        bin.size = 0;
        bin.created = "System Boot";
        bin.modified = "System Boot";
        bin.permissions = "rwxr-xr-x";
        currentDirContents.append(bin);
        
        FileEntry etc;
        etc.name = "etc";
        etc.path = "/etc";
        etc.type = "directory";
        etc.size = 0;
        etc.created = "System Boot";
        etc.modified = "System Boot";
        etc.permissions = "rwxr-xr-x";
        currentDirContents.append(etc);
        
        FileEntry home;
        home.name = "home";
        home.path = "/home";
        home.type = "directory";
        home.size = 0;
        home.created = "System Boot";
        home.modified = "System Boot";
        home.permissions = "rwxr-xr-x";
        currentDirContents.append(home);
        
        FileEntry lib;
        lib.name = "lib";
        lib.path = "/lib";
        lib.type = "directory";
        lib.size = 0;
        lib.created = "System Boot";
        lib.modified = "System Boot";
        lib.permissions = "rwxr-xr-x";
        currentDirContents.append(lib);
        
        FileEntry usr;
        usr.name = "usr";
        usr.path = "/usr";
        usr.type = "directory";
        usr.size = 0;
        usr.created = "System Boot";
        usr.modified = "System Boot";
        usr.permissions = "rwxr-xr-x";
        currentDirContents.append(usr);
    }
    // Handle /home directory
    else if (path == "/home") {
        FileEntry userFolder;
        userFolder.name = "user";
        userFolder.path = "/home/user";
        userFolder.type = "directory";
        userFolder.size = 0;
        userFolder.created = "System Boot";
        userFolder.modified = "System Boot";
        userFolder.permissions = "rwxr-xr-x";
        currentDirContents.append(userFolder);
        
        FileEntry readme;
        readme.name = "readme.txt";
        readme.path = "/home/readme.txt";
        readme.type = "file";
        readme.size = 2048;
        readme.created = "2024-05-10 10:30:00";
        readme.modified = "2024-05-10 10:30:00";
        readme.permissions = "rw-r--r--";
        currentDirContents.append(readme);
    }
    // Handle /home/user directory
    else if (path == "/home/user") {
        FileEntry documents;
        documents.name = "Documents";
        documents.path = "/home/user/Documents";
        documents.type = "directory";
        documents.size = 0;
        documents.created = "2024-05-10 10:00:00";
        documents.modified = "2024-05-10 10:00:00";
        documents.permissions = "rwxr-xr-x";
        currentDirContents.append(documents);
        
        FileEntry downloads;
        downloads.name = "Downloads";
        downloads.path = "/home/user/Downloads";
        downloads.type = "directory";
        downloads.size = 0;
        downloads.created = "2024-05-10 10:00:00";
        downloads.modified = "2024-05-10 10:00:00";
        downloads.permissions = "rwxr-xr-x";
        currentDirContents.append(downloads);
        
        FileEntry document;
        document.name = "document.txt";
        document.path = "/home/user/document.txt";
        document.type = "file";
        document.size = 4096;
        document.created = "2024-05-10 11:15:00";
        document.modified = "2024-05-10 12:30:00";
        document.permissions = "rw-------";
        currentDirContents.append(document);
    }
    // Handle /etc directory
    else if (path == "/etc") {
        FileEntry passwd;
        passwd.name = "passwd";
        passwd.path = "/etc/passwd";
        passwd.type = "file";
        passwd.size = 1024;
        passwd.created = "System Boot";
        passwd.modified = "System Boot";
        passwd.permissions = "rw-r--r--";
        currentDirContents.append(passwd);
        
        FileEntry fstab;
        fstab.name = "fstab";
        fstab.path = "/etc/fstab";
        fstab.type = "file";
        fstab.size = 512;
        fstab.created = "System Boot";
        fstab.modified = "System Boot";
        fstab.permissions = "rw-r--r--";
        currentDirContents.append(fstab);
    }
    // Handle /bin directory
    else if (path == "/bin") {
        FileEntry bash;
        bash.name = "bash";
        bash.path = "/bin/bash";
        bash.type = "file";
        bash.size = 8192;
        bash.created = "System Boot";
        bash.modified = "System Boot";
        bash.permissions = "rwxr-xr-x";
        currentDirContents.append(bash);
        
        FileEntry ls;
        ls.name = "ls";
        ls.path = "/bin/ls";
        ls.type = "file";
        ls.size = 4096;
        ls.created = "System Boot";
        ls.modified = "System Boot";
        ls.permissions = "rwxr-xr-x";
        currentDirContents.append(ls);
    }
    // All other directories are empty by default
    
    // Refresh the file list
    refreshFileList();
}

void FileBrowser::refreshFileList()
{
    ui->fileListWidget->clear();
    
    // Add parent directory entry if not at root
    if (currentPath != "/") {
        QListWidgetItem *parentItem = new QListWidgetItem("..");
        parentItem->setIcon(QIcon(":/icons/filebrowser.png"));
        ui->fileListWidget->addItem(parentItem);
    }
    
    // Add files and directories
    for (const FileEntry &entry : currentDirContents) {
        QListWidgetItem *item = new QListWidgetItem(entry.name);
        if (entry.type == "directory") {
            item->setIcon(QIcon(":/icons/filebrowser.png"));
        } else {
            item->setIcon(QIcon(":/icons/text-editor.png"));
        }
        ui->fileListWidget->addItem(item);
    }
    
    // Update stats
    int dirCount = 0;
    int fileCount = 0;
    int totalSize = 0;
    
    for (const FileEntry &entry : currentDirContents) {
        if (entry.type == "directory") {
            dirCount++;
        } else {
            fileCount++;
            totalSize += entry.size;
        }
    }
    
    ui->statsLabel->setText(QString("Directories: %1 | Files: %2 | Total Size: %3 KB")
                           .arg(dirCount)
                           .arg(fileCount)
                           .arg(totalSize / 1024));
}

void FileBrowser::onFileDoubleClicked(QListWidgetItem *item)
{
    QString itemName = item->text();
    
    // Handle parent directory
    if (itemName == "..") {
        int lastSlash = currentPath.lastIndexOf('/');
        if (lastSlash > 0) {
            navigateToDirectory(currentPath.left(lastSlash));
        } else {
            navigateToDirectory("/");
        }
        return;
    }
    
    // Find the clicked item in our list
    for (const FileEntry &entry : currentDirContents) {
        if (entry.name == itemName) {
            if (entry.type == "directory") {
                navigateToDirectory(entry.path);
            } else {
                // Show file content (simulated)
                QMessageBox::information(this, "File Content", 
                                        QString("Viewing file: %1\n\n"
                                               "Size: %2 bytes\n"
                                               "Created: %3\n"
                                               "Modified: %4\n"
                                               "Permissions: %5\n\n"
                                               "Content would be displayed here.")
                                        .arg(entry.path)
                                        .arg(entry.size)
                                        .arg(entry.created)
                                        .arg(entry.modified)
                                        .arg(entry.permissions));
            }
            return;
        }
    }
}

void FileBrowser::on_backButton_clicked()
{
    if (!pathHistory.isEmpty()) {
        QString previousPath = pathHistory.takeLast();
        currentPath = previousPath;
        navigateToDirectory(previousPath);
    }
}

void FileBrowser::on_homeButton_clicked()
{
    navigateToDirectory("/home/user");
}

void FileBrowser::on_refreshButton_clicked()
{
    refreshFileList();
}

void FileBrowser::on_createButton_clicked()
{
    QStringList options;
    options << "File" << "Directory";
    
    bool ok;
    QString type = QInputDialog::getItem(this, "Create New", "Select type:", options, 0, false, &ok);
    
    if (ok && !type.isEmpty()) {
        QString name;
        if (type == "File") {
            name = QInputDialog::getText(this, "Create New File", "Enter file name:", QLineEdit::Normal, "", &ok);
            
            if (ok && !name.isEmpty()) {
                createVirtualFile(name);
            }
        } else {
            name = QInputDialog::getText(this, "Create New Directory", "Enter directory name:", QLineEdit::Normal, "", &ok);
            
            if (ok && !name.isEmpty()) {
                createVirtualDirectory(name);
            }
        }
    }
}

void FileBrowser::createVirtualFile(const QString &fileName)
{
    // Check if file already exists
    for (const FileEntry &entry : currentDirContents) {
        if (entry.name == fileName) {
            QMessageBox::warning(this, "Error", "A file or directory with that name already exists.");
            return;
        }
    }
    
    // Create new file entry
    FileEntry newFile;
    newFile.name = fileName;
    newFile.path = currentPath + "/" + fileName;
    newFile.type = "file";
    newFile.size = QRandomGenerator::global()->bounded(1024, 8192);
    newFile.created = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    newFile.modified = newFile.created;
    newFile.permissions = "rw-r--r--";
    
    currentDirContents.append(newFile);
    refreshFileList();
}

void FileBrowser::createVirtualDirectory(const QString &dirName)
{
    // Check if directory already exists
    for (const FileEntry &entry : currentDirContents) {
        if (entry.name == dirName) {
            QMessageBox::warning(this, "Error", "A file or directory with that name already exists.");
            return;
        }
    }
    
    // Create new directory entry
    FileEntry newDir;
    newDir.name = dirName;
    newDir.path = currentPath + "/" + dirName;
    newDir.type = "directory";
    newDir.size = 0;
    newDir.created = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    newDir.modified = newDir.created;
    newDir.permissions = "rwxr-xr-x";
    
    currentDirContents.append(newDir);
    refreshFileList();
}

void FileBrowser::on_deleteButton_clicked()
{
    QListWidgetItem *item = ui->fileListWidget->currentItem();
    if (!item || item->text() == "..") {
        QMessageBox::warning(this, "Error", "Please select a valid file or directory to delete.");
        return;
    }
    
    QString name = item->text();
    
    // Find the selected item in our list
    for (int i = 0; i < currentDirContents.size(); i++) {
        if (currentDirContents[i].name == name) {
            // System directories can't be deleted
            if (currentPath == "/" && (name == "bin" || name == "etc" || 
                                     name == "home" || name == "lib" || name == "usr")) {
                QMessageBox::critical(this, "Permission Denied", 
                                    "Cannot delete system directories.");
                return;
            }
            
            // Confirm deletion
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirm Delete", 
                                         QString("Are you sure you want to delete '%1'?")
                                         .arg(name),
                                         QMessageBox::Yes|QMessageBox::No);
            
            if (reply == QMessageBox::Yes) {
                currentDirContents.remove(i);
                refreshFileList();
            }
            return;
        }
    }
}

void FileBrowser::on_closeButton_clicked()
{
    accept();
}