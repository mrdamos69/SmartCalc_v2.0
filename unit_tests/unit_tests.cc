#include <gtest/gtest.h>

#include "../model/model.h"

TEST(Test_s21_smart_calc, test_1) {
    Model test;
    string input = "3+4*2/(1-5)^2";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 3.5);
}

TEST(Test_s21_smart_calc, test_2) {
    Model test;
    string input = "1+2+3+4*5*6^7";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ((int)result, 5598726);
}

TEST(Test_s21_smart_calc, test_3) {
    Model test;
    string input = "123.456+2*3^4";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ((int)result, 285.456);
}

TEST(Test_s21_smart_calc, test_4) {
    Model test;
    string input = "(8+2*5)/(1+3*2-4)";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ((int)result, 6);
}

TEST(Test_s21_smart_calc, test_5) {
    Model test;
    string input = "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ((int)result, 10);
}

TEST(Test_s21_smart_calc, test_6) {
    Model test;
    string input = "cos(1*2)-1";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, -1.41614683655);
}

TEST(Test_s21_smart_calc, test_7) {
    Model test;
    string input = "cos(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))-1";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, -1.83907152908);
}

TEST(Test_s21_smart_calc, test_8) {
    Model test;
    string input = "sin(cos(5))";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 0.27987335076);
}

TEST(Test_s21_smart_calc, test_9) {
    Model test;
    string input = "2.33mod1";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 0.33);
}

TEST(Test_s21_smart_calc, test_10) {
    Model test;
    string input = "3+4*2/1-5+2^2";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 10);
}

TEST(Test_s21_smart_calc, test_11) {
    Model test;
    double x = 0.0003;
    string input = "asin(2*x)";
    double result = test.ScanLineEdit(input, x);
    ASSERT_EQ(result, 0.0006);
}

TEST(Test_s21_smart_calc, test_12) {
    Model test;
    double x = 0.0019;
    string input = "acos(2*x)";
    double result = test.ScanLineEdit(input, x);
    ASSERT_EQ(result, 1.567);
}

TEST(Test_s21_smart_calc, test_13) {
    Model test;
    double x = 0.0019;
    string input = "atan(2*x)";
    double result = test.ScanLineEdit(input, x);
    ASSERT_EQ(result, 0.00379998);
}

TEST(Test_s21_smart_calc, test_14) {
    Model test;
    double x = 0.004;
    string input = "tan(2*x)";
    double result = test.ScanLineEdit(input, x);
    ASSERT_EQ(result, 0.00800017);
}

TEST(Test_s21_smart_calc, test_15) {
    Model test;
    double x = 25;
    string input = "sqrt(2*x)";
    double result = test.ScanLineEdit(input, x);
    ASSERT_EQ(result, 7.07107);
}
TEST(Test_s21_smart_calc, test_16) {
    Model test;
    double x = 2;
    string input = "ln(10*x)";
    double result = test.ScanLineEdit(input, x);
    ASSERT_EQ(result, 2.99573);
}

TEST(Test_s21_smart_calc, test_17) {
    Model test;
    double x = 2;
    string input = "log(10*x)";
    double result = test.ScanLineEdit(input, x);
    ASSERT_EQ(result, 1.30103);
}

TEST(Test_s21_smart_calc, test_18) {
    Model test;
    string input = "()";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 0);
}

TEST(Test_s21_smart_calc, test_19) {
    Model test;
    string input = "3-(-3)";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 6);
}

TEST(Test_s21_smart_calc, test_20) {
    Model test;
    string input = "3-(+3)";
    double result = test.ScanLineEdit(input, 0);
    ASSERT_EQ(result, 0);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
