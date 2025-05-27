QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myos-gui
TEMPLATE = app

SOURCES += main.cpp \
    modeselection.cpp \
    resourceallocation.cpp \
    maindashboard.cpp \
    texteditor.cpp \
    calculator.cpp \
    memorystatus.cpp \
    minigames.cpp \
    calendar.cpp \
    clock.cpp \
    systeminfo.cpp \
    pcbtable.cpp \
    filebrowser.cpp

HEADERS += \
    modeselection.h \
    resourceallocation.h \
    maindashboard.h \
    texteditor.h \
    calculator.h \
    memorystatus.h \
    minigames.h \
    sharedmemory.h \
    calendar.h \
    clock.h \
    systeminfo.h \
    pcbtable.h \
    filebrowser.h

FORMS += \
    modeselection.ui \
    resourceallocation.ui \
    maindashboard.ui \
    texteditor.ui \
    calculator.ui \
    memorystatus.ui \
    minigames.ui \
    calendar.ui \
    clock.ui \
    systeminfo.ui \
    pcbtable.ui \
    filebrowser.ui

RESOURCES += \
    resources.qrc
HEADERS += teamcredits.h
SOURCES += teamcredits.cpp

HEADERS += bingogame.h
SOURCES += bingogame.cpp
