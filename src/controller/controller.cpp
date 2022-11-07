#include "controller.h"

 double Controller::add(double a) {
   model.add(a);
   return model.getData();
 }

 double Controller::sub(double a) {
   model.add(-a);
   return model.getData();
 }

 double Controller::mult(double a) {
   model.mult(a);
   return model.getData();
 }

 double Controller::div(double a) {
   model.mult(1.0 / a);
   return model.getData();
 }

 double Controller::pow(double a) {
   model.pow(a);
   return model.getData();
 }

 double Controller::mod(double a) {
   model.mod(a);
   return model.getData();
 }

 double Controller::cos(double a) {
   model.cos(a);
   return model.getData();
 }

 double Controller::sin(double a) {
   model.sin(a);
   return model.getData();
 }

 double Controller::tan(double a) {
   model.tan(a);
   return model.getData();
 }

 double Controller::acos(double a) {
   model.acos(a);
   return model.getData();
 }

 double Controller::asin(double a) {
   model.asin(a);
   return model.getData();
 }

 double Controller::atan(double a) {
   model.atan(a);
   return model.getData();
 }

 double Controller::sqrt(double a) {
   model.sqrt(a);
   return model.getData();
 }
 double Controller::ln(double a) {
   model.ln(a);
   return model.getData();
 }
 double Controller::log(double a) {
   model.log(a);
   return model.getData();
 }

double Controller::input_calc(std::string input_str, double in_x) {
  return model.ScanLineEdit(input_str, in_x);
}

 void Controller::reset() { model.reset(); }
