#ifndef DEPOSIT_CALC_H
#define DEPOSIT_CALC_H

#include <qvector.h>

#include <QDialog>
#include <QStandardItemModel>

#include "table.h"

namespace Ui {
class deposit_calc;
}

namespace s21 {

class deposit_calc : public QDialog {
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
  void on_pushButton_clicked();

  void on_horizontalSlider_valueChanged(int value);

 private:
  Ui::deposit_calc *ui;
  table *new_table;
  int rows = 0;
  int rows_2 = 0;
  QVector<std::pair<QDate, double>> add_sub_money;
  s21::Controller contr_deposit;

  void refresh();

 signals:
  void signal_all_sum(double);
  void signal_procent(double);
  void signal_size(int);
  void signal_data(QDate);
  void signal_check(bool);
  void signal_add_sub_money(QVector<std::pair<QDate, double>>);
};

}  // namespace s21

#endif  // DEPOSIT_CALC_H
