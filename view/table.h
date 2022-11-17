#ifndef TABLE_H
#define TABLE_H

#include <QDateTime>
#include <QDialog>
#include <QTableWidgetItem>
#include <cmath>

#include "../controller/controller.h"

namespace Ui {
class table;
}

class table : public QDialog {
  Q_OBJECT

 public:
  explicit table(QWidget *parent = nullptr);
  ~table();
  void check_calc();
  void anuitet_calc();
  void deposit_calc();
  void diferic_calc();
  void add_table(double result, double mec_sum, double mec_procent,
                 double remains);

 private:
  Ui::table *ui;
  QString data;
  QTableWidgetItem *item, *item_1, *item_2, *item_3, *item_4;
  double sum_credit, procent;
  int size, count;
  bool check, check_deposit;
  QVector<std::pair<QDateTime, double>> add_sub_money;
  QDateTime data_time;
  Controller contr_table;

 public slots:
  void slot_all_sum(double all_sum);
  void slot_procent(double procent);
  void slot_size_credit(int size_credit);
  void slot_data_credit(QDateTime data);
  void slot_check(bool check);
  void slot_check_deposit(bool check);
  void slot_add_sub_money(QVector<std::pair<QDateTime, double>> money);
};

#endif  // TABLE_H
