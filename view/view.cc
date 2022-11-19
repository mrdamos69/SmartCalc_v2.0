#include "view.h"

#include "graph.h"
#include "ui_view.h"

s21::View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View) {
  ui->setupUi(this);
  graph_func = new s21::Graph;
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(this, &View::signal_text, graph_func, &s21::Graph::slot_text);
  connect(this, &View::signal_x, graph_func, &s21::Graph::slot_x);
}

s21::View::~View() {
  if (graph_func != nullptr) {
    delete graph_func;
    graph_func = nullptr;
  }
  delete ui;
}

void s21::View::digits_numbers() {
  clean_result();
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void s21::View::digits_operations() {
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(button->text());
}

void s21::View::on_pushButton_L_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "(");
}

void s21::View::on_pushButton_R_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + ")");
}

void s21::View::on_pushButton_acos_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "acos(");
}

void s21::View::on_pushButton_asin_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "asin(");
}

void s21::View::on_pushButton_atan_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
}

void s21::View::on_pushButton_cos_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "cos(");
}

void s21::View::on_pushButton_div_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void s21::View::on_pushButton_ln_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "ln(");
}

void s21::View::on_pushButton_log_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "log(");
}

void s21::View::on_pushButton_mod_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "mod");
}

void s21::View::on_pushButton_mult_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void s21::View::on_pushButton_plus_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void s21::View::on_pushButton_pow_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "^");
}

void s21::View::on_pushButton_result_clicked() {
  double x = 0;
  clean_view = true;
  if (ui->lineEdit_2->text() != "") {
    x = (ui->lineEdit_2->text().toDouble());
  }
  ui->lineEdit->setText(QString::number(
      contr_result.input_calc(ui->lineEdit->text().toStdString(), x), 'g', 15));
}

void s21::View::on_pushButton_sin_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "sin(");
}

void s21::View::on_pushButton_sin_2_clicked() {
  clean_result();
  ui->lineEdit->setText("");
}

void s21::View::on_pushButton_sqrt_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "sqrt(");
}

void s21::View::on_pushButton_sub_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void s21::View::on_pushButton_tan_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "tan(");
}

void s21::View::on_pushButton_tch_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void s21::View::on_pushButton_x_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "x");
}

void s21::View::clean_result() {
  if (clean_view) {
    ui->lineEdit->setText("");
    clean_view = false;
  }
}

void s21::View::on_pushButton_graph_clicked() {
  emit signal_text(ui->lineEdit->text());
  emit signal_x(ui->lineEdit_2->text());
  graph_func->print_graph();
  graph_func->show();
}

void s21::View::on_pushButton_credit_calc_clicked() {
  calc_dialog = new s21::credit_calc;
  calc_dialog->show();
}

void s21::View::on_pushButton_deposit_calc_clicked() {
  deposit_dialog = new s21::deposit_calc;
  deposit_dialog->show();
}
