#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Pomodoro.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void configure();

public slots:
    void startPomodoro();
    void resetPomodoro();
    void updateTimerDisplay(int remainingTime, QString formattedRemaining);

private:
    Ui::MainWindow *ui;
    Pomodoro mPomodoro;

};

#endif // MAINWINDOW_H
