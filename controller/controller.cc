#include "controller.h"

double Controller::input_calc(std::string input_str, double in_x) {
  return model.ScanLineEdit(input_str, in_x);
}

double Controller::anuitet_calc(double &sum_credit, double &procent, int &size,
                                double &month_sum, double &month_procent,
                                double &remains) {
  return model.anuitet_calc(sum_credit, procent, size, month_sum, month_procent,
                            remains);
}

double Controller::diferic_calc(double &sum_credit, double &procent, int &size,
                                double &month_sum, double &month_procent,
                                double &remains) {
  return model.diferic_calc(sum_credit, procent, size, month_sum, month_procent,
                            remains);
}

double
Controller::deposit_calc(QVector<std::pair<QDateTime, double>> &add_sub_money,
                         QDateTime &data, double &procent,
                         double &month_procent, double &profit) {
  return model.deposit_calc(add_sub_money, data, procent, month_procent,
                            profit);
}

void Controller::all_prifit(double &profit, double &procent_money) {
  return model.all_prifit(profit, procent_money);
}

void Controller::reset() { model.reset(); }
