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

  double deposit_calc(
      const std::vector<std::pair<std::string, double>> &add_sub_money,
      const std::string &data, const double &procent, double &month_procent,
      double &profit);

  void all_prifit(double &profit, double &procent_money);

  void reset();
};

}  //  namespace s21

#endif
