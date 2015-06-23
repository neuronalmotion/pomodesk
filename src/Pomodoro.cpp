#include "Pomodoro.h"

#include <QDebug>

Pomodoro::Pomodoro(QObject *parent)
    : QObject(parent),
    mWorkDuration(0),
    mShortBreakDuration(0),
    mLongBreakDuration(0)
{
    connect(&mTimer, &QTimer::timeout, this, &Pomodoro::update);
}

Pomodoro::~Pomodoro()
{

}

void Pomodoro::start()
{
    mTime.start();
    mTimer.start(1000);
}

void Pomodoro::update()
{
    qDebug() << mTime.elapsed() << " secs elapsed";
    int remaining = mWorkDuration - mTime.elapsed() / 1000;
    int hours = remaining / 60;
    int seconds = remaining % 60;
    QString formattedRemaining;
    formattedRemaining.sprintf("%02d:%02d", hours, seconds);
    emit remainingTime(remaining, formattedRemaining);
}

void Pomodoro::setWorkDuration(const int &duration)
{
    mWorkDuration = duration;
}

int Pomodoro::getWorkDuration() const
{
    return mWorkDuration;
}

void Pomodoro::setShortBreakDuration(const int &duration)
{
    mShortBreakDuration = duration;
}

int Pomodoro::getShortBreakDuration() const
{
    return mShortBreakDuration;
}

void Pomodoro::setLongBreakDuration(const int &duration)
{
    mLongBreakDuration = duration;
}

int Pomodoro::getLongBreakDuration() const
{
    return mLongBreakDuration;
}
