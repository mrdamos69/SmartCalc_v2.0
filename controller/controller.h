#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

//#include <QDateTime>

class Controller {
private:
  Model model;

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
                  
  void all_prifit(double &profit, double &procent_money);
  void reset();
};

#endif
