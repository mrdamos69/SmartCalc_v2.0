#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {

class Controller {
 private:
  s21::Model model;

 public:
  double input_calc(const std::string &input_str, double in_x);
  double anuitet_calc(const double &sum_credit, const double &procent,
                      const int &size, double &month_sum, double &month_procent,
                      double &remains);

  double diferic_calc(const double &sum_credit, const double &procent,
                      const int &size, double &month_sum, double &month_procent,
                      double &remains);

  double deposit_calc(QVector<std::pair<QDate, double>> &add_sub_money,
                      QDate &data, double &procent, double &month_procent,
                      double &profit);

  QVector<std::pair<QDate, double>> push_line_table(
      QVector<std::pair<QDate, double>> &input_arr, QDate date, double value);

  void all_prifit(double &profit, double &procent_money);

  std::pair<QVector<double>, QVector<double>> print_graph(double &xBegin,
                                                          double &xEnd,
                                                          QString &input);

  void reset();
};

}  //  namespace s21

#endif
