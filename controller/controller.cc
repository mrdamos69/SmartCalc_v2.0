#include "controller.h"

double s21::Controller::input_calc(const std::string &input_str, double in_x) {
  return model.ScanLineEdit(input_str, in_x);
}

double s21::Controller::anuitet_calc(const double &sum_credit,
                                     const double &procent, const int &size,
                                     double &month_sum, double &month_procent,
                                     double &remains) {
  return model.anuitet_calc(sum_credit, procent, size, month_sum, month_procent,
                            remains);
}

double s21::Controller::diferic_calc(const double &sum_credit,
                                     const double &procent, const int &size,
                                     double &month_sum, double &month_procent,
                                     double &remains) {
  return model.diferic_calc(sum_credit, procent, size, month_sum, month_procent,
                            remains);
}

double s21::Controller::deposit_calc(
    const std::vector<std::pair<std::string, double>> &add_sub_money,
    const std::string &data, const double &procent, double &month_procent,
    double &profit) {
  return model.deposit_calc(add_sub_money, data, procent, month_procent,
                            profit);
}

void s21::Controller::all_prifit(double &profit, double &procent_money) {
  return model.all_prifit(profit, procent_money);
}

void s21::Controller::reset() { model.reset(); }
