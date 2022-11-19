#include "controller.h"

double s21::Controller::input_calc(std::string input_str, double in_x) {
  return model.ScanLineEdit(input_str, in_x);
}

double s21::Controller::anuitet_calc(double &sum_credit, double &procent,
                                     int &size, double &month_sum,
                                     double &month_procent, double &remains) {
  return model.anuitet_calc(sum_credit, procent, size, month_sum, month_procent,
                            remains);
}

double s21::Controller::diferic_calc(double &sum_credit, double &procent,
                                     int &size, double &month_sum,
                                     double &month_procent, double &remains) {
  return model.diferic_calc(sum_credit, procent, size, month_sum, month_procent,
                            remains);
}

double s21::Controller::deposit_calc(
    QVector<std::pair<QDateTime, double>> &add_sub_money, QDateTime &data,
    double &procent, double &month_procent, double &profit) {
  return model.deposit_calc(add_sub_money, data, procent, month_procent,
                            profit);
}

QVector<std::pair<QDateTime, double>> s21::Controller::push_line_table(
    QVector<std::pair<QDateTime, double>> &input_arr, QDateTime date,
    double value) {
  return model.push_line_table(input_arr, date, value);
}

void s21::Controller::all_prifit(double &profit, double &procent_money) {
  return model.all_prifit(profit, procent_money);
}

std::pair<QVector<double>, QVector<double>>
s21::Controller::print_graph(double &xBegin, double &xEnd, QString &input) {
  return model.print_graph(xBegin, xEnd, input);
}

void s21::Controller::reset() { model.reset(); }
