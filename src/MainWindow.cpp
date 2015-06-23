#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startPomodoro);
    connect(&mPomodoro, &Pomodoro::remainingTime, this, &MainWindow::updateTimerDisplay);
    configure();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configure()
{
    mPomodoro.setWorkDuration(25 * 60);
    ui->timerRemaining->setText(QString(mPomodoro.getWorkDuration()));
}

void MainWindow::startPomodoro()
{
    mPomodoro.start();
}

void MainWindow::resetPomodoro()
{
}

void MainWindow::updateTimerDisplay(int remainingTime, QString formattedRemaining)
{
    ui->timerRemaining->setText(formattedRemaining);
}
