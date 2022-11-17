#include "model.h"

Model::Model(Model &value) {
  while (!this->stack_calc.empty()) {
    this->stack_calc.pop_back();
  }
  this->stack_calc = value.stack_calc;
}

void Model::add(double a) { data += a; }
void Model::sub(double a) { data -= a; }
void Model::div(double a) { data /= a; }
void Model::mult(double a) { data *= a; }
void Model::pow(double a) { std::pow(data, a); }
void Model::mod(double a) { fmod(data, a); }
void Model::cos(double a) { data = std::cos(a); }
void Model::sin(double a) { data = std::sin(a); }
void Model::tan(double a) { data = std::tan(a); }
void Model::acos(double a) { data = std::acos(a); }
void Model::asin(double a) { data = std::asin(a); }
void Model::atan(double a) { data = std::atan(a); }
void Model::sqrt(double a) { data = std::sqrt(a); }
void Model::ln(double a) { data = std::log(a); }
void Model::log(double a) { data = std::log10(a); }
void Model::reset() { data = 0; }
double Model::getData() { return this->data; }

list<list_calc> Model::getStack() { return this->stack_calc; }

double Model::ReadNum(char *temp_str) {
  double num = atof(temp_str);
  delete[] temp_str;
  return num;
}

double Model::anuitet_calc(double &sum_credit, double &procent, int &size,
                           double &month_sum, double &month_procent,
                           double &remains) {
  double procent_year = (procent / 100) / (size <= 12 ? size : 12);
  double result =
      (sum_credit * procent_year * std::pow(1 + procent_year, size)) /
      (std::pow(1 + procent_year, size) - 1);
  month_procent = remains * procent_year;
  month_sum = result - month_procent;
  remains -= month_sum;
  return result;
}

double Model::diferic_calc(double &sum_credit, double &procent, int &size,
                           double &month_sum, double &month_procent,
                           double &remains) {
  month_procent = (remains * (procent / 100)) / (size <= 12 ? size : 12);
  month_sum = sum_credit / size;
  double result = month_sum + month_procent;
  remains -= (sum_credit / size);
  return result;
}

double Model::deposit_calc(QVector<std::pair<QDateTime, double>> &add_sub_money,
                           QDateTime &data, double &procent,
                           double &month_procent, double &profit) {
  double result = 0;
  for (auto value : add_sub_money) {
    if (value.first == data) {
      result += value.second;
    }
  }
  month_procent = profit * procent * 30 / 365 / 100;
  profit += month_procent;
  return result;
}

void Model::all_prifit(double &profit, double &procent_money) {
  profit += procent_money;
  procent_money = 0;
}

void Model::PushStack(type_act act, type_priority priority, double data) {
  list_calc temp(act, priority, data);
  this->stack_calc.push_back(temp);
  check_num = false;
}

void Model::ReversStack() {
  list<list_calc> new_steck;
  while (!stack_calc.empty()) {
    new_steck.push_back(stack_calc.back());
    stack_calc.pop_back();
  }
  std::swap(stack_calc, new_steck);
}

void Model::SortStation() {
  this->ReversStack();
  Model result;
  Model temp;
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
        temp.stack_calc.back().type != RIGHT)
      result.PushStack(temp.stack_calc.back().type, temp.stack_calc.back().prt,
                       0);
    temp.stack_calc.pop_back();
  }
  stack_calc = result.stack_calc;
}

void Model::add_temp_stack(Model &temp, Model &result) {
  if (!temp.stack_calc.empty()) {
    if ((stack_calc.back().prt > temp.stack_calc.back().prt) ||
        (stack_calc.back().type == LEFT)) {
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
        if (temp.stack_calc.back().type == RIGHT) {
          temp.stack_calc.pop_back();
        }
        if (temp.stack_calc.back().type == LEFT) {
          temp.stack_calc.pop_back();
        }
      }
    }
  } else {
    temp.PushStack(stack_calc.back().type, stack_calc.back().prt, 0);
  }
}

double Model::ScanLineEdit(string input, double in_x) {
  std::list<list_calc> input_stack;
  temp_num = new char[input.length()]();
  if (temp_num) {
    for (size_t i = 0, x = 0; i <= input.length(); i++) {
      switch (input[i]) {
      case '+':
        this->add_token_plus(input, x, i);
        break;
      case '-':
        this->add_token_sub(input, x, i);
        break;
      case '*':
        this->add_token_mult(input, x);
        break;
      case '/':
        this->add_token_div(input, x);
        break;
      case '^':
        this->add_token_pow(input, x);
        break;
      case 'm': // mod
        this->add_token_mod(x);
        break;
      case 'c': // cos(x)
        this->add_token_cos(input, i);
        break;
      case 's': // sin(x) // sqrt(x)
        this->add_token_sin(input, i);
        this->add_token_sqrt(input, i);
        break;
      case 't': // tan(x)
        this->add_token_tan(input, i);
        break;
      case 'a': // acos(x) // asin(x) // atan(x)
        this->add_token_acos(input, i);
        this->add_token_asin(input, i);
        this->add_token_atan(input, i);
        break;
      case 'l': // ln(x) // log(x)
        this->add_token_ln(input, i);
        this->add_token_log(input, i);
        break;
      case '(':
        this->add_token_left();
        break;
      case ')':
        this->add_token_right(input, x);
        break;
      default:
        this->read_number(input, x, i, in_x);
        break;
      }
    }
    delete[] temp_num;
  }
  this->SortStation();
  return this->calculation(this->stack_calc);
}

void Model::add_token_plus(string &input, size_t &x, size_t &position) {
  if (input[position - 1] == '(') {
    temp_num[x++] = input[position];
  } else {
    if (check_num)
      this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
    this->PushStack(PLUS, LOW_PR, 0);
    temp_num = new char[input.length()]();
    x = 0;
  }
}

void Model::add_token_sub(std::string &input, size_t &x, size_t &position) {
  if (input[position - 1] == '(') {
    temp_num[x++] = input[position];
  } else {
    if (check_num)
      this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
    this->PushStack(MINUS, LOW_PR, 0);
    temp_num = new char[input.length()];
    x = 0;
  }
}

void Model::add_token_div(std::string &input, size_t &x) {
  if (check_num)
    this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
  this->PushStack(DIV, MEDIUM_PR, 0);
  temp_num = new char[input.length()];
  x = 0;
}

void Model::add_token_mult(std::string &input, size_t &x) {
  if (check_num)
    this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
  this->PushStack(MULT, MEDIUM_PR, 0);
  temp_num = new char[input.length()];
  x = 0;
}

void Model::add_token_pow(std::string &input, size_t &x) {
  if (check_num)
    this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
  this->PushStack(POW, HIGH_PR, 0);
  temp_num = new char[input.length()];
  x = 0;
}

void Model::add_token_mod(size_t &x) {
  if (check_num)
    this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
  this->PushStack(MOD, MEDIUM_PR, 0);
  x = 0;
}

void Model::add_token_cos(std::string &input, size_t &position) {
  if (input[position + 1] == 'o' ? input[position + 2] == 's' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(COS, HIGH_PR, 0);
    ;
  }
}

void Model::add_token_sin(std::string &input, size_t &position) {
  if (input[position + 1] == 'i' ? input[position + 2] == 'n' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(SIN, HIGH_PR, 0);
  }
}

void Model::add_token_tan(std::string &input, size_t &position) {
  if (input[position + 1] == 'a' ? input[position + 2] == 'n' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(TAN, HIGH_PR, 0);
  }
}

void Model::add_token_acos(std::string &input, size_t &position) {
  if (input[position + 1] == 'c'
          ? input[position + 2] == 'o' ? input[position + 3] == 's' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(ACOS, HIGH_PR, 0);
  }
}

void Model::add_token_asin(std::string &input, size_t &position) {
  if (input[position + 1] == 's'
          ? input[position + 2] == 'i' ? input[position + 3] == 'n' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(ASIN, HIGH_PR, 0);
  }
}

void Model::add_token_atan(std::string &input, size_t &position) {
  if (input[position + 1] == 't'
          ? input[position + 2] == 'a' ? input[position + 3] == 'n' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(ATAN, HIGH_PR, 0);
  }
}

void Model::add_token_sqrt(std::string &input, size_t &position) {
  if (input[position + 1] == 'q'
          ? input[position + 2] == 'r' ? input[position + 3] == 't' ? 1 : 0 : 0
          : 0) {
    position += 3;
    this->PushStack(SQRT, HIGH_PR, 0);
  }
}

void Model::add_token_ln(std::string &input, size_t &position) {
  if (input[position + 1] == 'n' ? 1 : 0) {
    position += 1;
    this->PushStack(LN, HIGH_PR, 0);
  }
}

void Model::add_token_log(std::string &input, size_t &position) {
  if (input[position + 1] == 'o' ? input[position + 2] == 'g' ? 1 : 0 : 0) {
    position += 2;
    this->PushStack(LOG, HIGH_PR, 0);
  }
}

void Model::add_token_left() { this->PushStack(LEFT, LLOW_PR, 0); }

void Model::add_token_right(std::string &input, size_t &x) {
  if (check_num)
    this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
  this->PushStack(RIGHT, LLOW_PR, 0);
  this->temp_num = new char[input.length()];
  x = 0;
}

void Model::add_number(std::string &input, size_t &x) {
  if (check_num)
    this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
  this->temp_num = new char[input.length()];
  x = 0;
}

void Model::read_number(std::string &input, size_t &x, size_t &position,
                        double &in_x) {
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
  default:
    this->add_number(input, x);
    break;
  }
}

double Model::calculation(list<list_calc> &head) {
  this->ReversStack();
  Model temp;
  this->reset();
  int count = 2;
  double b = 0;
  while (!head.empty()) {
    if (head.back().prt == 0) {
      temp.PushStack(stack_calc.back().type, stack_calc.back().prt,
                     stack_calc.back().num);
    } else if ((stack_calc.back().prt > 0) &&
               (stack_calc.back().type < COS && stack_calc.back().type > 0)) {
      while (!temp.stack_calc.empty()) {
        if (count == 2) {
          b = temp.stack_calc.back().num;
        } else if (count == 1) {
          data = temp.stack_calc.back().num;
        } else if (count == 0) {
          break;
        }
        count--;
        temp.stack_calc.pop_back();
      }
      if (count == 0) {
        temp.PushStack(stack_calc.back().type, stack_calc.back().prt,
                       this->arichmetics(b, stack_calc.back().type));
      }
      count = 2;
    } else if ((stack_calc.back().prt > 0) && (stack_calc.back().type > MOD &&
                                               stack_calc.back().type < LEFT)) {
      while (!temp.stack_calc.empty()) {
        if (count == 2) {
          b = temp.stack_calc.back().num;
        } else if (count == 1) {
          break;
        }
        count--;
        temp.stack_calc.pop_back();
      }
      if (count == 1) {
        temp.PushStack(stack_calc.back().type, stack_calc.back().prt,
                       this->triganimetric(b, stack_calc.back().type));
      }
      count = 2;
    }
    head.pop_back();
  }
  if (!temp.stack_calc.empty()) {
    data = temp.stack_calc.back().num;
  }
  return data;
}

double Model::arichmetics(double b, int sumbol) {
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

double Model::triganimetric(double a, int sumbol) {
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
