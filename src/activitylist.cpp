#include "activitylist.h"
#include "ui_activitylist.h"

ActivityList::ActivityList(QWidget *parent, QList<Activity*> *list) :
    QDialog(parent),
    ui(new Ui::ActivityList)
{
    ui->setupUi(this);
    ui->delete_button->setEnabled(false);
    ui->modify_button->setEnabled(false);

    QStandardItemModel *model = new QStandardItemModel(0,2,this); //2 Rows and 3 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Content")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Interval/Time")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Repetitive?")));

    ui->tableView->setColumnWidth(0, ui->tableView->width() / 4);
    ui->tableView->setColumnWidth(1, ui->tableView->width() / 2);
    ui->tableView->setColumnWidth(2, ui->tableView->width() / 4);

    for(int i = 0;i < (*list).length(); i++) {
        Activity *current_activity = (*list)[i];
        QStandardItem *content = new QStandardItem(current_activity->getNotificationContent());
        QStandardItem *interval = new QStandardItem(QString("%1").arg(current_activity->getInterval()));
        QStandardItem *isRepetitive = new QStandardItem(QString("%1").arg(current_activity->getIsRepetitive()));

        if(!current_activity->getIsRepetitive()) {
            interval = new QStandardItem(current_activity->getDateTime());
        }

        model->setItem(i, 0, content);
        model->setItem(i, 1, interval);
        model->setItem(i, 2, isRepetitive);
        qDebug() << current_activity->getNotificationContent() << " " << current_activity->getIsRepetitive();
    }


    ui->tableView->setModel(model);

}

ActivityList::~ActivityList()
{
    delete ui;
}

void ActivityList::on_ok_button_clicked()
{
    this->close();
}

void ActivityList::on_tableView_clicked(const QModelIndex &index)
{
    qDebug() << index.row();
    ui->tableView->selectRow(index.row());
}

void ActivityList::on_tableView_activated(const QModelIndex &index)
{
    qDebug() << "activated";
}

void ActivityList::on_tableView_pressed(const QModelIndex &index)
{
    qDebug() << "pressed";
}

void ActivityList::on_tableView_entered(const QModelIndex &index)
{
    qDebug() << "entered";
}
