#include "activity.h"

Activity::Activity(QString notificationContent, int mSecInterval, bool isRepetitive)
{
    this->notificationContent = notificationContent;
    this->mSecInterval = mSecInterval;
    this->isRepetitve = isRepetitive;

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

void Activity::notifyMainwindow()
{
    emit timeout(this);
}
