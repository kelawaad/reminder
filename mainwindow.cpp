#include "mainwindow.h"
#include "ui_mainwindow.h"

// TODO: Show popup notification


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    activities = new QList<Activity*>();
    trayIcon = new QSystemTrayIcon();
    trayIcon->setContextMenu(NULL);
    trayIcon->show();
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(notificationClicked()));
}

void MainWindow::addActivity(Activity *act)
{
    trayIcon->showMessage("New Activity", "New activity is added");
    qDebug() << "New Activity is being added";
    qDebug() << "Content: " << act->getNotificationContent();
    qDebug() << "Interval: " << act->getInterval();
    qDebug() << "Is Repetitive: " << act->getIsRepetitive();
    activities->append(act);

    connect(act, SIGNAL(timeout(Activity*)), this, SLOT(showNotification(Activity*)));
}

void MainWindow::notificationClicked()
{
    qDebug() << "Ballon clicked";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Show a dialog to add a new activity
    qDebug() << "Button Clicked";
    dial = new ActivityDialog(this);
    connect(dial, SIGNAL(newActivity(Activity*)), this, SLOT(addActivity(Activity*)));
    dial->setModal(true);
    dial->show();
}

void MainWindow::showNotification(Activity *act)
{
    QString notificationContent = act->getNotificationContent();
    qDebug() << notificationContent;
    trayIcon->showMessage("Time out", notificationContent);
    //qDebug() << "Notification should appear now";
}
