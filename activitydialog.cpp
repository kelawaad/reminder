#include "activitydialog.h"
#include "ui_activitydialog.h"

ActivityDialog::ActivityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityDialog)
{
    ui->setupUi(this);
    ui->repetitiveRadioButton->click();
}

ActivityDialog::~ActivityDialog()
{
    delete ui;
}

void ActivityDialog::on_repetitiveRadioButton_clicked()
{
    ui->signleShotRadioButton->setChecked(false);
    ui->timeLabel->setText("Interval(ms)");
    ui->time->setText("");
}

void ActivityDialog::on_signleShotRadioButton_clicked()
{
    ui->signleShotRadioButton->setChecked(true);
    ui->timeLabel->setText("Time(ms)");
    ui->time->setText("");
}

void ActivityDialog::on_pushButton_clicked()
{
    ActivityDialog::close();
}
