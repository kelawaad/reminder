#ifndef ACTIVITYDIALOG_H
#define ACTIVITYDIALOG_H

#include <QDialog>
#include <activity.h>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class ActivityDialog;
}

class ActivityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityDialog(QWidget *parent = 0);
    ~ActivityDialog();

private slots:
    void on_repetitiveRadioButton_clicked();

    void on_signleShotRadioButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::ActivityDialog *ui;
    QWidget *parent;

signals:
    void newActivity(Activity*);
};

#endif // ACTIVITYDIALOG_H
