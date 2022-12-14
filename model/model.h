#ifndef MODEL_H
#define MODEL_H

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>

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
  string temp_num;
  bool check_num;

 public:
  Model() : data(0), temp_num(""), check_num(false){};
  Model(const Model &value);

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

  void add_token_plus(const string &input, size_t &x, const size_t &position);
  void add_token_sub(const string &input, size_t &x, const size_t &position);
  void add_token_div(size_t &x);
  void add_token_mult(size_t &x);
  void add_token_pow(size_t &x);
  void add_token_mod(size_t &x);
  void add_token_cos(const std::string &input, size_t &position);
  void add_token_sin(const std::string &input, size_t &position);
  void add_token_tan(const std::string &input, size_t &position);
  void add_token_acos(const std::string &input, size_t &position);
  void add_token_asin(const std::string &input, size_t &position);
  void add_token_atan(const std::string &input, size_t &position);
  void add_token_sqrt(const std::string &input, size_t &position);
  void add_token_ln(const std::string &input, size_t &position);
  void add_token_log(const std::string &input, size_t &position);
  void add_token_left();
  void add_token_right(size_t &x);
  void add_number(size_t &x);
  void read_number(const std::string &input, size_t &x, const size_t &position,
                   const double &in_x);

  void PushStack(type_act act, type_priority priority, double data);
  double ReadNum();

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
  void ReversStack();
  void SortStation();
  void add_temp_stack(Model &temp, Model &result);
  double calculation(list<list_calc> &head);
  double arichmetics(double b, int sumbol);
  double triganimetric(double a, int sumbol);
};

}  // namespace s21

#endif
