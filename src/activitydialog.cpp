#include "activitydialog.h"
#include "ui_activitydialog.h"

ActivityDialog::ActivityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityDialog)
{
    ui->setupUi(this);
    ui->repetitiveRadioButton->click();
    ui->single_shot_label->hide();
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
}

void ActivityDialog::on_signleShotRadioButton_clicked()
{
    ui->signleShotRadioButton->setChecked(true);
    ui->time->hide();
    ui->single_shot_label->setText("Time");
    ui->single_shot_label->show();
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
        QString event_time = ui->singleshot_time_edit->text();
        QStringList lst = event_time.split(' ');
        QStringList time = lst[0].split(':');

        int hours = time[0].toInt();
        int minutes = time[1].toInt();
        if(lst[1] == "PM") {
            hours += 12;
            hours %= 24;
        }

        QTime current_time = QTime().currentTime();
        interval = current_time.msecsTo(QTime(hours, minutes));
    }
    Activity *act = new Activity(notificationContent, interval, isRepetitive);

    emit(newActivity(act));

    ActivityDialog::close();
}
