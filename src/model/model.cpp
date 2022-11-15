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

double Model::ScanLineEdit(string input, double in_x) {
  std::list<list_calc> input_stack;
  temp_num = new char[input.length()]();
  if (temp_num) {
    for (size_t i = 0, x = 0; i <= input.length(); i++) {
      switch (input[i]) {
      case '+':
        if (input[i - 1] == '(') {
          temp_num[x++] = input[i];
        } else {
          if (check_num)
            this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
          this->PushStack(PLUS, LOW_PR, 0);
          temp_num = new char[input.length()]();
          x = 0;
        }
        break;
      case '-':
        if (input[i - 1] == '(') {
          temp_num[x++] = input[i];
        } else {
          if (check_num)
            this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
          this->PushStack(MINUS, LOW_PR, 0);
          temp_num = new char[input.length()];
          x = 0;
        }
        break;
      case '*':
        if (check_num)
          this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
        this->PushStack(MULT, MEDIUM_PR, 0);
        temp_num = new char[input.length()];
        x = 0;
        break;
      case '/':
        if (check_num)
          this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
        this->PushStack(DIV, MEDIUM_PR, 0);
        temp_num = new char[input.length()];
        x = 0;
        break;
      case '^':
        if (check_num)
          this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
        this->PushStack(POW, HIGH_PR, 0);
        temp_num = new char[input.length()];
        x = 0;
        break;
      case 'm': // mod
        if (input[i + 1] == 'o' ? input[i + 2] == 'd' ? 1 : 0 : 0) {
          i += 2;
          if (check_num)
            this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
          this->PushStack(MOD, MEDIUM_PR, 0);
          x = 0;
        }
        break;
      case 'c': // cos(x)
        if (input[i + 1] == 'o' ? input[i + 2] == 's' ? 1 : 0 : 0) {
          i += 2;
          this->PushStack(COS, HIGH_PR, 0);
          ;
        }
        break;
      case 's': // sin(x) // sqrt(x)
        if (input[i + 1] == 'i' ? input[i + 2] == 'n' ? 1 : 0 : 0) {
          i += 2;
          this->PushStack(SIN, HIGH_PR, 0);
        }
        if (input[i + 1] == 'q'
                ? input[i + 2] == 'r' ? input[i + 3] == 't' ? 1 : 0 : 0
                : 0) {
          i += 3;
          this->PushStack(SQRT, HIGH_PR, 0);
        }
        break;
      case 't': // tan(x)
        if (input[i + 1] == 'a' ? input[i + 2] == 'n' ? 1 : 0 : 0) {
          i += 2;
          this->PushStack(TAN, HIGH_PR, 0);
        }
        break;
      case 'a': // acos(x) // asin(x) // atan(x)
        if (input[i + 1] == 'c'
                ? input[i + 2] == 'o' ? input[i + 3] == 's' ? 1 : 0 : 0
                : 0) {
          i += 3;
          this->PushStack(ACOS, HIGH_PR, 0);
        }
        if (input[i + 1] == 's'
                ? input[i + 2] == 'i' ? input[i + 3] == 'n' ? 1 : 0 : 0
                : 0) {
          i += 3;
          this->PushStack(ASIN, HIGH_PR, 0);
        }
        if (input[i + 1] == 't'
                ? input[i + 2] == 'a' ? input[i + 3] == 'n' ? 1 : 0 : 0
                : 0) {
          i += 3;
          this->PushStack(ATAN, HIGH_PR, 0);
        }
        break;
      case 'l': // ln(x) // log(x)
        if (input[i + 1] == 'n' ? 1 : 0) {
          i += 1;
          this->PushStack(LN, HIGH_PR, 0);
        }
        if (input[i + 1] == 'o' ? input[i + 2] == 'g' ? 1 : 0 : 0) {
          i += 2;
          this->PushStack(LOG, HIGH_PR, 0);
        }
        break;
      case '(':
        this->PushStack(LEFT, LLOW_PR, 0);
        break;
      case ')':
        if (check_num)
          this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
        this->PushStack(RIGHT, LLOW_PR, 0);
        this->temp_num = new char[input.length()];
        x = 0;
        break;
      case 'x':
        this->PushStack(NUMBER, NUM, in_x);
        break;
      case '.':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '0':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '1':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '2':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '3':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '4':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '5':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '6':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '7':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '8':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      case '9':
        temp_num[x++] = input[i];
        check_num = true;
        break;
      default:
        if (check_num)
          this->PushStack(NUMBER, NUM, this->ReadNum(temp_num));
        this->temp_num = new char[input.length()];
        x = 0;
        break;
      }
    }
    delete[] temp_num;
  }
  this->SortStation();

  return this->calculation(this->stack_calc);
}

// void Model::PrintStack(list<list_calc> &input) {
//   list<list_calc> temp(input);
//   while (!temp.empty()) {
//     if (temp.back().prt != 0) {
//       printf("%s", temp.back().type == 3 ? "+" : "");
//       printf("%s", temp.back().type == 4 ? "-" : "");
//       printf("%s", temp.back().type == 5 ? "/" : "");
//       printf("%s", temp.back().type == 6 ? "*" : "");
//       printf("%s", temp.back().type == 7 ? "^" : "");
//       printf("%s", temp.back().type == 8 ? "mod" : "");
//       printf("%s", temp.back().type == 11 ? "cos" : "");
//       printf("%s", temp.back().type == 12 ? "sin" : "");
//       printf("%s", temp.back().type == 13 ? "tan" : "");
//       printf("%s", temp.back().type == 14 ? "acos" : "");
//       printf("%s", temp.back().type == 15 ? "asin" : "");
//       printf("%s", temp.back().type == 16 ? "atan" : "");
//       printf("%s", temp.back().type == 17 ? "sqrt" : "");
//       printf("%s", temp.back().type == 18 ? "ln" : "");
//       printf("%s", temp.back().type == 19 ? "log" : "");
//       printf("%s", temp.back().type == 20 ? "(" : "");
//       printf("%s", temp.back().type == 21 ? ")" : "");
//       printf(" ");
//     } else {
//       std::cout << temp.back().num << " ";
//     }
//     temp.pop_back();
//   }
//   std::cout << "\n";
// }

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
  // this->reset();
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
  // this->reset();
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
