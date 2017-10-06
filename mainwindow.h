#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <activity.h>
#include <activitydialog.h>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QString>
#include <QList>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void removeActivity(Activity);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<Activity*> *activities;
    ActivityDialog *dial;
    QSystemTrayIcon *trayIcon;

private slots:
    //void popup();
    void on_pushButton_clicked();
    void showNotification(Activity*);
    void addActivity(Activity*);
    void notificationClicked();
};

#endif // MAINWINDOW_H
