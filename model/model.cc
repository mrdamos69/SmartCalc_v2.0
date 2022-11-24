#include "model.h"

s21::Model::Model(const s21::Model &value)
    : data(0), temp_num(""), check_num(false) {
  while (!this->stack_calc.empty()) {
    this->stack_calc.pop_back();
  }
  this->stack_calc = value.stack_calc;
}

void s21::Model::add(double a) { this->data += a; }
void s21::Model::sub(double a) { this->data -= a; }
void s21::Model::div(double a) { this->data /= a; }
void s21::Model::mult(double a) { this->data *= a; }
void s21::Model::mod(double a) { this->data = fmod(data, a); }
void s21::Model::cos(double a) { this->data = std::cos(a); }
void s21::Model::sin(double a) { this->data = std::sin(a); }
void s21::Model::tan(double a) { this->data = std::tan(a); }
void s21::Model::acos(double a) { this->data = std::acos(a); }
void s21::Model::asin(double a) { this->data = std::asin(a); }
void s21::Model::atan(double a) { this->data = std::atan(a); }
void s21::Model::sqrt(double a) { this->data = std::sqrt(a); }
void s21::Model::ln(double a) { this->data = std::log(a); }
void s21::Model::log(double a) { this->data = std::log10(a); }
void s21::Model::reset() { this->data = 0; }
double s21::Model::getData() { return this->data; }
void s21::Model::pow(double a) { this->data = std::pow(data, a); }
list<s21::list_calc> s21::Model::getStack() { return this->stack_calc; }

double s21::Model::ReadNum() {
  double num = atof(temp_num.data());
  temp_num = "";
  temp_num.resize(255);
  return num;
}

double s21::Model::anuitet_calc(const double &sum_credit, const double &procent,
                                const int &size, double &month_sum,
                                double &month_procent, double &remains) {
  double procent_year = (procent / 100) / (size <= 12 ? size : 12);
  double result =
      (sum_credit * procent_year * std::pow(1 + procent_year, size)) /
      (std::pow(1 + procent_year, size) - 1);
  month_procent = remains * procent_year;
  month_sum = result - month_procent;
  remains -= month_sum;
  return result;
}

double s21::Model::diferic_calc(const double &sum_credit, const double &procent,
                                const int &size, double &month_sum,
                                double &month_procent, double &remains) {
  month_procent = (remains * (procent / 100)) / (size <= 12 ? size : 12);
  month_sum = sum_credit / size;
  double result = month_sum + month_procent;
  remains -= (sum_credit / size);
  return result;
}

double s21::Model::deposit_calc(
    const std::vector<std::pair<std::string, double>> &add_sub_money,
    const std::string &data, const double &procent, double &month_procent,
    double &profit) {
  double result = 0;
  for (auto &&value : add_sub_money) {
    if (value.first == data) {
      result += value.second;
    }
  }
  month_procent = profit * procent * 30 / 365 / 100;
  profit += month_procent;
  return result;
}

void s21::Model::all_prifit(double &profit, double &procent_money) {
  profit += procent_money;
  procent_money = 0;
}

void s21::Model::PushStack(type_act act, type_priority priority, double data) {
  list_calc temp(act, priority, data);
  this->stack_calc.push_back(temp);
  check_num = false;
}

void s21::Model::ReversStack() {
  list<list_calc> new_steck;
  while (!stack_calc.empty()) {
    new_steck.push_back(stack_calc.back());
    stack_calc.pop_back();
  }
  std::swap(stack_calc, new_steck);
}

void s21::Model::SortStation() {
  this->ReversStack();
  s21::Model result;
  s21::Model temp;
  while (!stack_calc.empty()) {
    int menu = stack_calc.back().prt;
    switch (menu) {
      case 0:
        result.PushStack(NUMBER, NUM, stack_calc.back().num);
        break;
      default:
        this->add_temp_stack(temp, result);
        break;
    }
    stack_calc.pop_back();
  }
  while (!temp.stack_calc.empty()) {
    if (temp.stack_calc.back().type != LEFT &&
        temp.stack_calc.back().type != RIGHT) {
      result.PushStack(temp.stack_calc.back().type, temp.stack_calc.back().prt,
                       0);
    }
    temp.stack_calc.pop_back();
  }
  stack_calc = result.stack_calc;
}

void s21::Model::add_temp_stack(s21::Model &temp, s21::Model &result) {
  if (!temp.stack_calc.empty()) {
    if ((stack_calc.back().prt > temp.stack_calc.back().prt) ||
        (stack_calc.back().type == LEFT) || stack_calc.back().type == POW) {
      temp.PushStack(stack_calc.back().type, stack_calc.back().prt, 0);
    } else {
      if (stack_calc.back().type == RIGHT) {
        while ((!temp.stack_calc.empty()) &&
               (temp.stack_calc.back().type != LEFT)) {
          result.PushStack(temp.stack_calc.back().type,
                           temp.stack_calc.back().prt, 0);
          temp.stack_calc.pop_back();
        }
      } else {
        result.PushStack(temp.stack_calc.back().type,
                         temp.stack_calc.back().prt, 0);
        temp.stack_calc.pop_back();
      }
      temp.PushStack(stack_calc.back().type, stack_calc.back().prt, 0);
      if (result.stack_calc.back().type < COS) {
        if (temp.stack_calc.back().type == RIGHT) temp.stack_calc.pop_back();
        if (temp.stack_calc.back().type == LEFT) temp.stack_calc.pop_back();
      }
    }
  } else {
    temp.PushStack(stack_calc.back().type, stack_calc.back().prt, 0);
  }
}

double s21::Model::ScanLineEdit(string input, double in_x) {
  for (size_t i = 0, x = 0; i < (input.length() + 1); i++) {
    switch (input[i]) {
      case '+':
        this->add_token_plus(input, x, i);
        break;
      case '-':
        this->add_token_sub(input, x, i);
        break;
      case '*':
        this->add_token_mult(x);
        break;
      case '/':
        this->add_token_div(x);
        break;
      case '^':
        this->add_token_pow(x);
        break;
      case 'm':  // mod
        this->add_token_mod(x);
        break;
      case 'c':  // cos(x)
        this->add_token_cos(input, i);
        break;
      case 's':  // sin(x) // sqrt(x)
        this->add_token_sin(input, i);
        this->add_token_sqrt(input, i);
        break;
      case 't':  // tan(x)
        this->add_token_tan(input, i);
        break;
      case 'a':  // acos(x) // asin(x) // atan(x)
        this->add_token_acos(input, i);
        this->add_token_asin(input, i);
        this->add_token_atan(input, i);
        break;
      case 'l':  // ln(x) // log(x)
        this->add_token_ln(input, i);
        this->add_token_log(input, i);
        break;
      case '(':
        this->add_token_left();
        break;
      case ')':
        this->add_token_right(x);
        break;
      default:
        this->read_number(input, x, i, in_x);
        break;
    }
  }
  temp_num.resize(255);
  this->SortStation();
  return this->calculation(this->stack_calc);
}

void s21::Model::add_token_plus(const std::string &input, size_t &x,
                                const size_t &position) {
  if (input[position - 1] == '(') {
    temp_num[x++] = input[position];
  } else if (input[position - 1] == 'e' || input[position - 1] == 'E') {
    temp_num[x++] = input[position];
    check_num = true;
  } else {
    if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
    this->PushStack(PLUS, LOW_PR, 0);
    x = 0;
  }
}

void s21::Model::add_token_sub(const std::string &input, size_t &x,
                               const size_t &position) {
  if (input[position - 1] == '(') {
    temp_num[x++] = input[position];
  } else {
    if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
    this->PushStack(MINUS, LOW_PR, 0);
    x = 0;
  }
}

void s21::Model::add_token_div(size_t &x) {
  if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
  this->PushStack(DIV, MEDIUM_PR, 0);
  x = 0;
}

void s21::Model::add_token_mult(size_t &x) {
  if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
  this->PushStack(MULT, MEDIUM_PR, 0);
  x = 0;
}

void s21::Model::add_token_pow(size_t &x) {
  if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
  this->PushStack(POW, HIGH_PR, 0);
  ;
  x = 0;
}

void s21::Model::add_token_mod(size_t &x) {
  if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
  this->PushStack(MOD, MEDIUM_PR, 0);
  x = 0;
}

void s21::Model::add_token_cos(const std::string &input, size_t &position) {
  if (input[position + 1] == 'o' ? input[position + 2] == 's' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(COS, HIGH_PR, 0);
    ;
  }
}

void s21::Model::add_token_sin(const std::string &input, size_t &position) {
  if (input[position + 1] == 'i' ? input[position + 2] == 'n' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(SIN, HIGH_PR, 0);
  }
}

void s21::Model::add_token_tan(const std::string &input, size_t &position) {
  if (input[position + 1] == 'a' ? input[position + 2] == 'n' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(TAN, HIGH_PR, 0);
  }
}

void s21::Model::add_token_acos(const std::string &input, size_t &position) {
  if (input[position + 1] == 'c'
          ? input[position + 2] == 'o' ? input[position + 3] == 's' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(ACOS, HIGH_PR, 0);
  }
}

void s21::Model::add_token_asin(const std::string &input, size_t &position) {
  if (input[position + 1] == 's'
          ? input[position + 2] == 'i' ? input[position + 3] == 'n' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(ASIN, HIGH_PR, 0);
  }
}

void s21::Model::add_token_atan(const std::string &input, size_t &position) {
  if (input[position + 1] == 't'
          ? input[position + 2] == 'a' ? input[position + 3] == 'n' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(ATAN, HIGH_PR, 0);
  }
}

void s21::Model::add_token_sqrt(const std::string &input, size_t &position) {
  if (input[position + 1] == 'q'
          ? input[position + 2] == 'r' ? input[position + 3] == 't' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(SQRT, HIGH_PR, 0);
  }
}

void s21::Model::add_token_ln(const std::string &input, size_t &position) {
  if (input[position + 1] == 'n' ? 1 : 0) {
    position += 1;
    this->PushStack(LN, HIGH_PR, 0);
  }
}

void s21::Model::add_token_log(const std::string &input, size_t &position) {
  if (input[position + 1] == 'o' ? input[position + 2] == 'g' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(LOG, HIGH_PR, 0);
  }
}

void s21::Model::add_token_left() { this->PushStack(LEFT, LLOW_PR, 0); }

void s21::Model::add_token_right(size_t &x) {
  if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
  this->PushStack(RIGHT, LLOW_PR, 0);
  x = 0;
}

void s21::Model::add_number(size_t &x) {
  if (check_num) this->PushStack(NUMBER, NUM, this->ReadNum());
  x = 0;
}

void s21::Model::read_number(const std::string &input, size_t &x,
                             const size_t &position, const double &in_x) {
  switch (input[position]) {
    case 'x':
      this->PushStack(NUMBER, NUM, in_x);
      break;
    case '.':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '0':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '1':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '2':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '3':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '4':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '5':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '6':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '7':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '8':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case '9':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case 'e':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    case 'E':
      temp_num[x++] = input[position];
      check_num = true;
      break;
    default:
      this->add_number(x);
      break;
  }
}

double s21::Model::calculation(list<list_calc> &head) {
  this->ReversStack();
  s21::Model temp;
  this->reset();
  double b;
  while (!head.empty()) {
    if (head.back().prt == 0) {
      temp.PushStack(stack_calc.back().type, stack_calc.back().prt,
                     stack_calc.back().num);
    } else if ((stack_calc.back().prt > 0) &&
               (stack_calc.back().type < COS && stack_calc.back().type > 0)) {
      if (!temp.stack_calc.empty()) {
        b = temp.stack_calc.back().num;
        temp.stack_calc.pop_back();
        data = temp.stack_calc.back().num;
        if (!temp.stack_calc.empty()) temp.stack_calc.pop_back();
      }
      temp.PushStack(NUMBER, NUM, this->arichmetics(b, stack_calc.back().type));
    } else if ((stack_calc.back().prt > 0) && (stack_calc.back().type > MOD &&
                                               stack_calc.back().type < LEFT)) {
      if (!temp.stack_calc.empty()) {
        b = temp.stack_calc.back().num;
        temp.stack_calc.pop_back();
        temp.PushStack(NUMBER, NUM,
                       this->triganimetric(b, stack_calc.back().type));
      }
    }
    head.pop_back();
  }
  if (!temp.stack_calc.empty()) {
    data = temp.stack_calc.back().num;
  }
  return data;
}

double s21::Model::arichmetics(double b, int sumbol) {
  if (sumbol == PLUS) {
    this->add(b);
  }
  if (sumbol == MINUS) {
    this->sub(b);
  }
  if (sumbol == DIV) {
    this->div(b);
  }
  if (sumbol == MULT) {
    this->mult(b);
  }
  if (sumbol == POW) {
    this->pow(b);
  }
  if (sumbol == MOD) {
    this->mod(b);
  }
  return data;
}

double s21::Model::triganimetric(double a, int sumbol) {
  if (sumbol == COS) {
    this->cos(a);
  }
  if (sumbol == SIN) {
    this->sin(a);
  }
  if (sumbol == TAN) {
    this->tan(a);
  }
  if (sumbol == ACOS) {
    this->acos(a);
  }
  if (sumbol == ASIN) {
    this->asin(a);
  }
  if (sumbol == ATAN) {
    this->atan(a);
  }
  if (sumbol == SQRT) {
    this->sqrt(a);
  }
  if (sumbol == LN) {
    this->ln(a);
  }
  if (sumbol == LOG) {
    this->log(a);
  }
  return data;
}
