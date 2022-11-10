#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QDialog>
#include <table.h>

namespace Ui {
class credit_calc;
}

class credit_calc : public QDialog {
    Q_OBJECT

public:
    explicit credit_calc(QWidget *parent = nullptr);
    ~credit_calc();

private slots:
    void on_horizontalSlider_actionTriggered(int action);
    void on_pushButton_clicked();

    void on_pushButton_result_clicked();

private:
    Ui::credit_calc *ui;
    table *new_table;

    int time_credit;  // количество месяцев
    int result_credit;  //платеж по кредиту в месяц
    int result_procent;  // сумма переплаты за прoценты

    void сalculation_credit();
};

#endif // CREDIT_CALC_H
