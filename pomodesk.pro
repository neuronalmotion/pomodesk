QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pomodesk
TEMPLATE = app

INCLUDEPATH += "src"

SOURCES += src/main.cpp\
        src/MainWindow.cpp

HEADERS  += src/MainWindow.h

FORMS    += src/MainWindow.ui
