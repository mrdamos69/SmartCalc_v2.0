#include <gtest/gtest.h>

#include "../model/model.h"

TEST(Test_s21_smart_calc, test_1) {
  s21::Model test;
  string input = "3+4*2/(1-5)^2";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ(result, 3.5);
}

TEST(Test_s21_smart_calc, test_2) {
  s21::Model test;
  string input = "1+2+3+4*5*6^7";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ((int)result, 5598726);
}

TEST(Test_s21_smart_calc, test_3) {
  s21::Model test;
  string input = "123.456+2*3^4";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ(result, 285.456);
}

TEST(Test_s21_smart_calc, test_4) {
  s21::Model test;
  string input = "(8+2*5)/(1+3*2-4)";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ((int)result, 6);
}

TEST(Test_s21_smart_calc, test_5) {
  s21::Model test;
  string input =
      "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ((int)result, 10);
}

TEST(Test_s21_smart_calc, test_6) {
  s21::Model test;
  string input = "cos(1*2)-1";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_DOUBLE_EQ(result, -1.4161468365471424);
}

TEST(Test_s21_smart_calc, test_7) {
  s21::Model test;
  string input =
      "cos(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/"
      "(7-(1+1))*3-(2+(1+1+1-1*2/2)))-1";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_DOUBLE_EQ(result, -1.8390715290764525);
}

TEST(Test_s21_smart_calc, test_8) {
  s21::Model test;
  string input = "sin(cos(5))";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_DOUBLE_EQ(result, 0.27987335076852737);
}

TEST(Test_s21_smart_calc, test_9) {
  s21::Model test;
  string input = "2.33mod1";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_DOUBLE_EQ(result, 0.33);
}

TEST(Test_s21_smart_calc, test_10) {
  s21::Model test;
  string input = "3+4*2/1-5+2^2";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ(result, 10);
}

TEST(Test_s21_smart_calc, test_11) {
  s21::Model test;
  double x = 0.0003;
  string input = "asin(2*x)";
  double result = test.ScanLineEdit(input, x);
  ASSERT_DOUBLE_EQ(result, 0.00060000003600000577);
}

TEST(Test_s21_smart_calc, test_12) {
  s21::Model test;
  double x = 0.0019;
  string input = "acos(2*x)";
  double result = test.ScanLineEdit(input, x);
  ASSERT_DOUBLE_EQ(result, 1.5669963176495039);
}

TEST(Test_s21_smart_calc, test_13) {
  s21::Model test;
  double x = 0.0019;
  string input = "atan(2*x)";
  double result = test.ScanLineEdit(input, x);
  ASSERT_DOUBLE_EQ(result, 0.0037999817094918021);
}

TEST(Test_s21_smart_calc, test_14) {
  s21::Model test;
  double x = 0.004;
  string input = "tan(2*x)";
  double result = test.ScanLineEdit(input, x);
  ASSERT_DOUBLE_EQ(result, 0.0080001706710358458);
}

TEST(Test_s21_smart_calc, test_15) {
  s21::Model test;
  double x = 25;
  string input = "sqrt(2*x)";
  double result = test.ScanLineEdit(input, x);
  ASSERT_DOUBLE_EQ(result, 7.0710678118654755);
}

TEST(Test_s21_smart_calc, test_16) {
  s21::Model test;
  double x = 2;
  string input = "ln(10*x)";
  double result = test.ScanLineEdit(input, x);
  ASSERT_DOUBLE_EQ(result, 2.9957322735539909);
}

TEST(Test_s21_smart_calc, test_17) {
  s21::Model test;
  double x = 2;
  string input = "log(10*x)";
  double result = test.ScanLineEdit(input, x);
  ASSERT_DOUBLE_EQ(result, 1.3010299956639813);
}

TEST(Test_s21_smart_calc, test_18) {
  s21::Model test;
  string input = "()";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ(result, 0);
}

TEST(Test_s21_smart_calc, test_19) {
  s21::Model test;
  string input = "3-(-3)";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ(result, 6);
}

TEST(Test_s21_smart_calc, test_20) {
  s21::Model test;
  string input = "3-(+3)";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_EQ(result, 0);
}

TEST(Test_s21_smart_calc, test_21) {
    s21::Model test;
    string input = "2^2^3";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 256);
}

TEST(Test_s21_smart_calc, test_22) {
  s21::Model test;
  string input = "5.994e+2+4";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_DOUBLE_EQ(result, 603.4);
}

TEST(Test_s21_smart_calc, test_23) {
  s21::Model test;
  string input = "2.994e2-2*3";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_DOUBLE_EQ(result, 293.4);
}

TEST(Test_s21_smart_calc, test_24) {
  s21::Model test;
  string input = "2.994E2-2/cos(0.5*7)";
  double result = test.ScanLineEdit(input, 0);
  ASSERT_DOUBLE_EQ(result, 301.5357100943836);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
