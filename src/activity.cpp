#include "activity.h"

Activity::Activity(QString notificationContent, int mSecInterval, bool isRepetitive, QDateTime datetime)
{
    this->notificationContent = notificationContent;
    this->mSecInterval = mSecInterval;
    this->isRepetitive = isRepetitive;
    this->date = datetime;

    pop = new PopUp();
    pop->setPopupText(notificationContent);

    timer = new QTimer();
    timer->setSingleShot(!isRepetitive);
    timer->setInterval(mSecInterval);
    connect(timer, SIGNAL(timeout()), this, SLOT(notifyMainwindow()));
    startActivity();
}

void Activity::startActivity()
{
    if(!timer->isActive())
        timer->start();
}

void Activity::stopActivity()
{
    timer->stop();
}

void Activity::restartActivity()
{
    timer->start();
}

void Activity::setNotificationContent(QString notificationConent)
{
    this->notificationContent = notificationConent;
    pop->setPopupText(notificationConent);
}

void Activity::setIsRepetitive(bool isRepetitive)
{
    this->isRepetitive = isRepetitive;
}

void Activity::setDateTime(QDateTime datetime)
{
    this->date = datetime;
}

QString Activity::getNotificationContent()
{
    return this->notificationContent;
}

int Activity::getInterval()
{
    return this->mSecInterval;
}

bool Activity::getIsRepetitive()
{
    return this->isRepetitive;
}

QString Activity::getDateTime()
{
    return this->date.toString(Qt::SystemLocaleShortDate);
}

void Activity::notifyMainwindow()
{
    pop->show();
    if(!isRepetitive) {
        timer->stop();
        emit deleteActivity(this);
    }
}

