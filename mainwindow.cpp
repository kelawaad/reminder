#include "mainwindow.h"
#include "ui_mainwindow.h"


// TODO: add a settings window
// TODO: change the styling of the main window
// TODO: allow the user to create a reminder at a certain date and time

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    activities = new QList<Activity*>();

    QMenu *menu = new QMenu();
    menu -> addAction("View Main Window", this, SLOT(show()));
    menu -> addAction("Add Action", this, SLOT(on_pushButton_clicked()));
    menu -> addAction("Quit", this, SLOT(myClose()));

    QIcon icon;
    icon.addFile(":/icons/icons/notification_icon_32x31.png");

    trayIcon = new QSystemTrayIcon();
    trayIcon->setIcon(icon);
    trayIcon->setContextMenu(menu);
    trayIcon->show();

    quitActionActivated = false;

    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(notificationClicked()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::addActivity(Activity *act)
{
    if(act == NULL)
        return;
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

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
        this->show();
}

void MainWindow::myClose()
{
    quitActionActivated = true;
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
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


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!quitActionActivated)
    {
        event->ignore();
        this->hide();
    }
}
