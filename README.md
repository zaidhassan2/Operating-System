https://youtu.be/A4O1GlvfsOc


# Mini OS GUI: Ultimate Cross-Platform Setup Guide

## Project Overview

The **Mini OS GUI** is a comprehensive operating system simulation built with Qt and C++, featuring multiple applications including a text editor, calculator, file browser, and system resource manager. This SEO-optimized guide provides detailed instructions for setting up and running the project across all major operating systems.

## System Requirements

- **Processor**: 1GHz dual-core or better
- **Memory**: 512MB RAM minimum (1GB recommended)
- **Storage**: 50MB free disk space
- **Display**: 1024x768 resolution or higher

## Installation Guide by Operating System

### Ubuntu/Debian Linux

```bash
# Install required dependencies
sudo apt update
sudo apt install -y git build-essential cmake qtbase5-dev qt5-qmake libqt5widgets5 libqt5gui5 libqt5core5a python3 python3-tk

# Clone the repository
git clone https://github.com/zaidhassan2/Operating-System.git

# Navigate to project directory
cd Operating-System

# Make the executable runnable
chmod +x myos-gui

# Run the application
./myos-gui

# To run the automation testing tool
python3 new.py
```

### Fedora/RHEL Linux

```bash
# Install required dependencies
sudo dnf install -y git gcc-c++ cmake qt5-qtbase qt5-qtbase-devel python3 python3-tkinter

# Clone the repository
git clone https://github.com/zaidhassan2/Operating-System.git

# Navigate to project directory
cd Operating-System

# Make the executable runnable
chmod +x myos-gui

# Run the application
./myos-gui

# To run the automation testing tool
python3 new.py
```

### Arch Linux

```bash
# Install required dependencies
sudo pacman -S git base-devel cmake qt5-base python python-tkinter

# Clone the repository
git clone https://github.com/zaidhassan2/Operating-System.git

# Navigate to project directory
cd Operating-System

# Make the executable runnable
chmod +x myos-gui

# Run the application
./myos-gui

# To run the automation testing tool
python3 new.py
```

### macOS

```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install required dependencies
brew install git cmake qt@5 python

# Add Qt to PATH (you may need to adjust version number)
echo 'export PATH="/usr/local/opt/qt@5/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc

# Clone the repository
git clone https://github.com/zaidhassan2/Operating-System.git

# Navigate to project directory
cd Operating-System

# Make the executable runnable
chmod +x myos-gui

# Run the application
./myos-gui

# To run the automation testing tool
python3 new.py
```

### Windows

```powershell
# Install Chocolatey if not already installed (run in Administrator PowerShell)
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

# Install required dependencies
choco install git cmake qt5 python -y

# Clone the repository
git clone https://github.com/zaidhassan2/Operating-System.git

# Navigate to project directory
cd Operating-System

# Run the application
.\myos-gui.exe

# To run the automation testing tool
python new.py
```

## Building from Source (All Platforms)

If you need to build the project from source:

```bash
# Clone the repository
git clone https://github.com/zaidhassan2/Operating-System.git

# Navigate to the project directory
cd Operating-System

# Create a build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
make  # On Windows use: cmake --build . --config Release

# Run the application
./myos-gui  # On Windows use: .\Release\myos-gui.exe
```

## Using the Automation Testing Tool

The Python-based automation tool provides comprehensive testing capabilities:

1. Launch the tool: `python3 new.py`
2. Select the Mini OS GUI executable path
3. Choose a testing scenario from the dropdown
4. Click "Start Testing" to begin automated testing
5. View real-time logs in the execution log area
6. Save logs for future reference using the "Save Log" button

## Key Features Highlights

- **Intuitive Desktop Environment**: Modern interface with application shortcuts
- **Text Editor**: Create, edit, and save documents with a clean interface
- **Calculator**: Perform mathematical operations with a user-friendly calculator
- **File Browser**: Navigate and manage files with integrated file operations
- **Calendar Application**: Track dates and schedule events with a built-in calendar
- **System Monitor**: View CPU usage, memory allocation, and process tables
- **Resource Management**: Allocate and monitor system resources efficiently
- **Multi-application Support**: Run multiple applications simultaneously

## Troubleshooting Common Issues

1. **Missing Qt Libraries**: Install required Qt dependencies using your package manager
2. **Permission Denied**: Ensure executable permissions with `chmod +x myos-gui`
3. **Tkinter Missing**: Install Python Tkinter for the automation tool
4. **Build Errors**: Verify CMake installation and Qt development libraries

## Performance Optimization

For optimal Mini OS GUI performance:

- Allocate at least 2 CPU cores during resource allocation
- Assign minimum 512MB RAM in the resource allocation dialog
- Close unnecessary background applications
- Use SSD storage for faster application loading times

---
