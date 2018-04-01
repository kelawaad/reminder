#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <popup.h>
#include <QDateTime>

class Activity : public QObject
{

    Q_OBJECT

public:
    Activity(QString, int, bool, QDateTime);

    void startActivity();
    void stopActivity();
    void pauseActivity();
    void restartActivity();

    void setNotificationContent(QString);
    void setInterval(int);
    void setIsRepetitive(bool);
    void setDateTime(QDateTime);

    QString getNotificationContent();
    int getInterval();
    bool getIsRepetitive();
    QString getDateTime();

private:
    QString notificationContent;
    int mSecInterval;
    QTimer *timer;
    bool isRepetitive;
    PopUp *pop;
    QDateTime date;

private slots:
    void notifyMainwindow();
signals:
    void deleteActivity(Activity*);
    void timeout(Activity*);
};

#endif // ACTIVITY_H
