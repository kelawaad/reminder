#include "activitydialog.h"
#include "ui_activitydialog.h"

ActivityDialog::ActivityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityDialog)
{
    ui->setupUi(this);
}

ActivityDialog::~ActivityDialog()
{
    delete ui;
}
