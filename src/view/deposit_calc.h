#ifndef DEPOSIT_CALC_H
#define DEPOSIT_CALC_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class deposit_calc;
}

class deposit_calc : public QDialog
{
    Q_OBJECT

public:
    explicit deposit_calc(QWidget *parent = nullptr);
    ~deposit_calc();

private slots:
    void on_horizontalSlider_actionTriggered(int action);

    void on_add_money_clicked();

    void on_sub_money_clicked();

    void on_add_money_2_clicked();

    void on_sub_money_2_clicked();

private:
    Ui::deposit_calc *ui;
//    QStandardItemModel *model;
    int rows = 0;
    int rows_2 = 0;
};

#endif // DEPOSIT_CALC_H
