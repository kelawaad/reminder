#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>

class Activity
{
public:
    Activity();
    void startActivity();
    void stopActivity();
    void pauseActivity();
    void restartActivity();
    void setNotificationContent(QString);
    void setInterval(int);

    QString getNotificationContent();
    int getInterval();

private:
    QString notificationContent;
    int mSecInterval;
    QTimer *timer;
};

#endif // ACTIVITY_H
