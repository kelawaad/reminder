#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <activity.h>
#include <activitydialog.h>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QString>
#include <QList>
#include <QDebug>
#include <QIcon>
#include <QCloseEvent>

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
    bool quitActionActivated;               // Whether the quit action was called from the main window or the tray icon
    void closeEvent(QCloseEvent *event);

private slots:
    //void popup();
    void on_pushButton_clicked();
    void showNotification(Activity*);
    void addActivity(Activity*);
    void notificationClicked();
    void trayIconActivated(QSystemTrayIcon::ActivationReason);
    void myClose();
};

#endif // MAINWINDOW_H
