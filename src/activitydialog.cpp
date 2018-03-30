#include "activitydialog.h"
#include "ui_activitydialog.h"

ActivityDialog::ActivityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityDialog)
{
    ui->setupUi(this);
    ui->repetitiveRadioButton->click();
    ui->single_shot_label->hide();
    ui->single_shot_date->hide();
    ui->singleshot_time_edit->setTime(QTime::currentTime());
    ui->single_shot_date->setDate(QDate::currentDate());
    ui->single_shot_date->setDisplayFormat("MMM d yyyy");
    this->parent = parent;
}

ActivityDialog::~ActivityDialog()
{
    delete ui;
}

void ActivityDialog::on_repetitiveRadioButton_clicked()
{
    ui->signleShotRadioButton->setChecked(false);
    ui->repetitve_label->setText("Interval(ms)");
    ui->repetitve_label->show();
    ui->single_shot_label->hide();
    ui->time->show();
    ui->singleshot_time_edit->hide();
    ui->single_shot_date->hide();
}

void ActivityDialog::on_signleShotRadioButton_clicked()
{
    ui->signleShotRadioButton->setChecked(true);
    ui->time->hide();
    ui->single_shot_label->setText("Time");
    ui->single_shot_label->show();
    ui->single_shot_date->show();
    ui->repetitve_label->hide();
    ui->singleshot_time_edit->show();
}

void ActivityDialog::on_pushButton_clicked()
{
    QString notificationContent = ui->notificationContent->document()->toPlainText();
    bool isRepetitive = ui->repetitiveRadioButton->isChecked();
    int interval;
    if(isRepetitive)
        interval = ui->time->text().toInt();
    else {
        QDate selected_date = ui->single_shot_date->date();
        QTime selected_time = ui->singleshot_time_edit->time();
        interval = QDateTime::currentDateTime().msecsTo(QDateTime(selected_date, selected_time));
        if(interval < 0) {
            interval = 0;
            qDebug() << "Cannot create an event in the past";
            return;
        }
    }
    Activity *act = new Activity(notificationContent, interval, isRepetitive);

    emit(newActivity(act));

    ActivityDialog::close();
}
