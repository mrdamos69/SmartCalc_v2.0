#ifndef TABLE_H
#define TABLE_H

#include <QDate>
#include <QDialog>
#include <QTableWidgetItem>
#include <cmath>

#include "../controller/controller.h"

namespace Ui {
class table;
}

namespace s21 {

class table : public QDialog {
  Q_OBJECT

 public:
  explicit table(QWidget *parent = nullptr);
  ~table();
  void check_calc();
  void anuitet_calc();
  void deposit_calc();
  void diferic_calc();
  void result();
  void add_table(double result, double mec_sum, double mec_procent,
                 double remains);

 private:
  Ui::table *ui;
  QString data;
  QTableWidgetItem *item, *item_1, *item_2, *item_3, *item_4;
  std::vector<std::pair<std::string, double>> add_sub_money;
  QDate data_time;
  s21::Controller contr_table;
  double sum_credit, procent;
  int size, count;
  bool check, check_deposit;
  std::vector<std::pair<std::string, double>> to_std_vector(
      QVector<std::pair<QDate, double>> &add_sub_money);

 public slots:
  void slot_all_sum(double all_sum);
  void slot_procent(double procent);
  void slot_size_credit(int size_credit);
  void slot_data_credit(QDate data);
  void slot_check(bool check);
  void slot_check_deposit(bool check);
  void slot_add_sub_money(std::vector<std::pair<std::string, double>> money);
};

}  // namespace s21

#endif  // TABLE_H
