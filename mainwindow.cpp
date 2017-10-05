#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    activities = new QList<Activity*>();
}

void MainWindow::addActivity(Activity *act)
{
    //TODO: connect the timeout signal with the corresponding slot
    qDebug() << "New Activity is being added";
    qDebug() << "Content: " << act->getNotificationContent();
    qDebug() << "Interval: " << act->getInterval();
    qDebug() << "Is Repetitive: " << act->getIsRepetitive();
    activities->append(act);

    connect(act, SIGNAL(timeout(Activity*)), this, SLOT(showNotification(Activity*)));
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
    //QString notificationContent = act->getNotificationContent();
    qDebug() << "Notification should appear now";
}
