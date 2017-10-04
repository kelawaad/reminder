#ifndef ACTIVITYDIALOG_H
#define ACTIVITYDIALOG_H

#include <QDialog>

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
};

#endif // ACTIVITYDIALOG_H
