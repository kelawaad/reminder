#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <activity.h>
#include <QMainWindow>
#include <QString>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void addActivity(QString notificationContent, int mSecInterval);
    void removeActivity(Activity);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList activities;

private slots:
    void popup();
};

#endif // MAINWINDOW_H
