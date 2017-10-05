#include "activitydialog.h"
#include "ui_activitydialog.h"

ActivityDialog::ActivityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityDialog)
{
    ui->setupUi(this);
    ui->repetitiveRadioButton->click();
    this->parent = parent;
}

ActivityDialog::~ActivityDialog()
{
    delete ui;
}

void ActivityDialog::on_repetitiveRadioButton_clicked()
{
    ui->signleShotRadioButton->setChecked(false);
    ui->timeLabel->setText("Interval(ms)");
    //ui->time->setText("");
}

void ActivityDialog::on_signleShotRadioButton_clicked()
{
    ui->signleShotRadioButton->setChecked(true);
    ui->timeLabel->setText("Time(ms)");
    //ui->time->setText("");
}

void ActivityDialog::on_pushButton_clicked()
{
    QString notificationContent = ui->notificationContent->document()->toPlainText();
    bool isRepetitive = ui->repetitiveRadioButton->isChecked();
    int interval = ui->time->text().toInt();

    Activity *act = new Activity(notificationContent, interval, isRepetitive);

    emit(newActivity(act));

    ActivityDialog::close();
}
