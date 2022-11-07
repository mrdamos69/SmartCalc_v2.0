#ifndef MODEL_H
#define MODEL_H
#include <cmath>
#include <iostream>
#include <list>
#include <string>

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

class list_calc {
public:
  list_calc(type_act act, type_priority priority, double data)
      : prt(priority), num(data), type(act) {}
  type_priority prt;
  double num;
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
  Model() : data(0){};
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
  double ScanLineEdit(string inpu, double in_x);
  void PushStack(type_act act, type_priority priority, double data);
  double ReadNum(char *temp_str);
  void PrintStack(list<list_calc> &stack_calc);
  void ReversStack();
  void SortStation();
  double calculation(list<list_calc> &head);
  double arichmetics(double a, double b, int sumbol);
  double triganimetric(double a, int sumbol);
};

#endif
