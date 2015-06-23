QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pomodesk
TEMPLATE = app

INCLUDEPATH += "src"

SOURCES += src/main.cpp\
    src/MainWindow.cpp \
    src/Pomodoro.cpp

HEADERS  += src/MainWindow.h \
    src/Pomodoro.h

FORMS    += src/MainWindow.ui
