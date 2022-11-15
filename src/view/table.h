#ifndef TABLE_H
#define TABLE_H

#include <QDateTime>
#include <QDialog>
#include <QTableWidgetItem>
#include <cmath>

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
  void diferic_calc();
  void add_table(double result, double mec_sum, double mec_procent, double remains);


 private:
  Ui::table *ui;
  QString data;
  QTableWidgetItem *item, *item_1, *item_2, *item_3, *item_4;
  double sum_credit;
  double procent;
  int size;
  int count;
  bool check;
  QDateTime data_time;

 public slots:
  void slot_all_sum(double all_sum);
  void slot_procent(double procent);
  void slot_size_credit(int size_credit);
  void slot_data_credit(QDateTime data);
  void slot_check(bool check);
};

#endif  // TABLE_H
