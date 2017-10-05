#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QObject>
#include <QString>
#include <QTimer>

class Activity : public QObject
{

    Q_OBJECT

public:
    Activity(QString, int, bool);

    void startActivity();
    void stopActivity();
    void pauseActivity();
    void restartActivity();

    void setNotificationContent(QString);
    void setInterval(int);
    void setIsRepetitive(bool);

    QString getNotificationContent();
    int getInterval();
    bool getIsRepetitive();

private:
    QString notificationContent;
    int mSecInterval;
    QTimer *timer;
    bool isRepetitive;

private slots:
    void notifyMainwindow();

signals:
    void timeout(Activity*);
};

#endif // ACTIVITY_H
