#ifndef ACTIVITYLIST_H
#define ACTIVITYLIST_H

#include <QDialog>
#include <QDebug>
#include <activity.h>
#include <QStandardItemModel>
#include <QString>

namespace Ui {
class ActivityList;
}

class ActivityList : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityList(QWidget *parent = 0, QList<Activity*>* = NULL);
    ~ActivityList();

private slots:
    void on_ok_button_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_pressed(const QModelIndex &index);

    void on_tableView_entered(const QModelIndex &index);


private:
    Ui::ActivityList *ui;
};

#endif // ACTIVITYLIST_H
