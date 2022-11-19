#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {

class Controller {
private:
  s21::Model model;

public:
  double input_calc(std::string input_str, double in_x);
  double anuitet_calc(double &sum_credit, double &procent, int &size,
                      double &month_sum, double &month_procent,
                      double &remains);

  double diferic_calc(double &sum_credit, double &procent, int &size,
                      double &month_sum, double &month_procent,
                      double &remains);

  double deposit_calc(QVector<std::pair<QDateTime, double>> &add_sub_money,
                      QDateTime &data, double &procent, double &month_procent,
                      double &profit);

  QVector<std::pair<QDateTime, double>>
  push_line_table(QVector<std::pair<QDateTime, double>> &input_arr,
                  QDateTime date, double value);

  void all_prifit(double &profit, double &procent_money);

  std::pair<QVector<double>, QVector<double>>
  print_graph(double &xBegin, double &xEnd, QString &input);

  void reset();
};

} //  namespace s21

#endif
