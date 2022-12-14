#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <QDialog>

#include "table.h"

namespace Ui {
class credit_calc;
}

namespace s21 {

class credit_calc : public QDialog {
  Q_OBJECT

 public:
  explicit credit_calc(QWidget *parent = nullptr);
  ~credit_calc();

 private slots:
  void on_horizontalSlider_actionTriggered(int action);
  void on_pushButton_clicked();
  void on_differenc_calc_clicked(bool check);
  void on_annyitet_calc_clicked(bool check);

  void on_horizontalSlider_valueChanged(int value);

 private:
  Ui::credit_calc *ui;
  table *new_table;
  void refresh();
  bool this_annuetet;

  void сalculation_credit(bool check);
 signals:
  void signal_all_sum(double);
  void signal_procent(double);
  void signal_size_credit(int);
  void signal_data_credit(QDate);
  void signal_check(bool);
};

}  // namespace s21

#endif  // CREDIT_CALC_H
