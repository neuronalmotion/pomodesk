#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QTimer>

class Pomodoro : public QObject
{
    Q_OBJECT
public:
    Pomodoro(QObject *parent=0);
    ~Pomodoro();

    void start();

    void setWorkDuration(const int& duration);
    int getWorkDuration() const;

    void setShortBreakDuration(const int& duration);
    int getShortBreakDuration() const;

    void setLongBreakDuration(const int& duration);
    int getLongBreakDuration() const;

signals:
    void remainingTime(int remainingTime, QString formattedRemaining);

private slots:
    void update();

private:

    QTimer mTimer;
    QTime mTime;

    int mWorkDuration;
    int mShortBreakDuration;
    int mLongBreakDuration;
};

#endif // POMODORO_H
