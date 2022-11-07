#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

class Controller {
private:
  Model model;
public:
  double add(double a);
  double sub(double a);
  double div(double a);
  double mult(double a);
  double pow(double a);
  double mod(double a);
  double cos(double a);
  double sin(double a);
  double tan(double a);
  double acos(double a);
  double asin(double a);
  double atan(double a);
  double sqrt(double a);
  double ln(double a);
  double log(double a);
  double input_calc(std::string input_str, double in_x);
  void reset();
};

#endif
