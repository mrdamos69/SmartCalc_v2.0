#ifndef MODEL_H
#define MODEL_H

#include <cmath>
#include <iostream>
#include <list>
#include <string>

#include <QDateTime>

using std::list;
using std::string;

typedef enum {
  NUMBER = 1,
  X = 2,
  PLUS = 3,
  MINUS = 4,
  DIV = 5,
  MULT = 6,
  POW = 7,
  MOD = 8,
  COS = 11,
  SIN = 12,
  TAN = 13,
  ACOS = 14,
  ASIN = 15,
  ATAN = 16,
  SQRT = 17,
  LN = 18,
  LOG = 19,
  LEFT = 20,
  RIGHT = 21
} type_act;

typedef enum {
  HIGH_PR = 3,
  MEDIUM_PR = 2,
  LOW_PR = 1,
  NUM = 0,
  LLOW_PR = -1
} type_priority;

namespace s21 {

class list_calc {
public:
  list_calc(type_act act, type_priority priority, double data)
      : prt(priority), num(data), type(act) {}
  type_priority prt;
  double num = 0;
  type_act type;
};

class Model {
public:
  list<list_calc> stack_calc;

private:
  double data;
  char *temp_num;
  bool check_num = false;

public:
  Model() : data(0), temp_num(nullptr), check_num(false){};
  Model(Model &value);

  void add(double a);
  void sub(double a);
  void div(double a);
  void mult(double a);
  void pow(double a);
  void mod(double a);
  void cos(double a);
  void sin(double a);
  void tan(double a);
  void acos(double a);
  void asin(double a);
  void atan(double a);
  void sqrt(double a);
  void ln(double a);
  void log(double a);
  void reset();
  double getData();
  list<list_calc> getStack();
  double ScanLineEdit(string input, double in_x);

  void add_token_plus(string &input, size_t &x, size_t &position);
  void add_token_sub(string &input, size_t &x, size_t &position);
  void add_token_div(std::string &input, size_t &x);
  void add_token_mult(std::string &input, size_t &x);
  void add_token_pow(std::string &input, size_t &x);
  void add_token_mod(size_t &x);
  void add_token_cos(std::string &input, size_t &position);
  void add_token_sin(std::string &input, size_t &position);
  void add_token_tan(std::string &input, size_t &position);
  void add_token_acos(std::string &input, size_t &position);
  void add_token_asin(std::string &input, size_t &position);
  void add_token_atan(std::string &input, size_t &position);
  void add_token_sqrt(std::string &input, size_t &position);
  void add_token_ln(std::string &input, size_t &position);
  void add_token_log(std::string &input, size_t &position);
  void add_token_left();
  void add_token_right(std::string &input, size_t &x);
  void add_number(std::string &input, size_t &x);
  void read_number(std::string &input, size_t &x, size_t &position,
                   double &in_x);

  void PushStack(type_act act, type_priority priority, double data);
  double ReadNum(char *temp_str);

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

  std::pair<QVector<double>, QVector<double>>
  print_graph(double &xBegin, double &xEnd, QString &input);

  void all_prifit(double &profit, double &procent_money);

  void ReversStack();
  void SortStation();
  void add_temp_stack(Model &temp, Model &result);
  double calculation(list<list_calc> &head);
  double arichmetics(double b, int sumbol);
  double triganimetric(double a, int sumbol);
};

} // namespace s21

#endif
