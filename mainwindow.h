#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <activity.h>
#include <activitydialog.h>
#include <QMainWindow>
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
    void addActivity(QString notificationContent, int mSecInterval, bool isRepetitve);
    void removeActivity(Activity);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<Activity*> *activities;
    ActivityDialog *dial;

private slots:
    //void popup();
    void on_pushButton_clicked();
    void showNotification(Activity*);
};

#endif // MAINWINDOW_H
