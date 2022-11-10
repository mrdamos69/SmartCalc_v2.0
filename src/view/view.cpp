#include "view.h"
#include "graph.h"
#include "ui_view.h"

View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View) {
  ui->setupUi(this);
  graph_func = new Graph;
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

  connect(this, &View::signal_text, graph_func, &Graph::slot_text);
  connect(this, &View::signal_x, graph_func, &Graph::slot_x);

}

View::~View() { delete ui; }

void View::digits_numbers() {
  clean_result();
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void View::digits_operations() {
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(button->text());
}

void View::on_pushButton_L_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "(");
}

void View::on_pushButton_R_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + ")");
}

void View::on_pushButton_acos_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "acos(");
}

void View::on_pushButton_asin_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "asin(");
}

void View::on_pushButton_atan_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
}

void View::on_pushButton_cos_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "cos(");
}

void View::on_pushButton_div_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void View::on_pushButton_ln_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "ln(");
}

void View::on_pushButton_log_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "log(");
}

void View::on_pushButton_mod_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "mod");
}

void View::on_pushButton_mult_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void View::on_pushButton_plus_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void View::on_pushButton_pow_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "^");
}

void View::on_pushButton_result_clicked() {
   double x = 0;
   clean_view = true;
   QString send = ui->lineEdit->text();
   std::string ba = send.toStdString();

   if (ui->lineEdit_2->text() != "") {
     x = (ui->lineEdit_2->text().toDouble());
   }

   QString toStr = QString::number(contr_result.input_calc(ba, x), 'g', 15);
   ui->lineEdit->setText(toStr);

}

void View::on_pushButton_sin_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "sin(");
}

void View::on_pushButton_sin_2_clicked() {
  clean_result();
  ui->lineEdit->setText("");
}

void View::on_pushButton_sqrt_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "sqrt(");
}

void View::on_pushButton_sub_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void View::on_pushButton_tan_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + "tan(");
}

void View::on_pushButton_tch_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void View::on_pushButton_x_clicked() {
  clean_result();
  ui->lineEdit->setText(ui->lineEdit->text() + "x");
}

void View::clean_result() {
  if (clean_view) {
    ui->lineEdit->setText("");
    clean_view = false;
  }
}

void View::on_pushButton_graph_clicked() {
    emit signal_text(ui->lineEdit->text());
    emit signal_x(ui->lineEdit_2->text());
    graph_func->print_graph();
    graph_func->show();
}

void View::on_pushButton_credit_calc_clicked() {
    calc_dialog = new credit_calc;
    calc_dialog->show();
}

void View::on_pushButton_deposit_calc_clicked() {
    deposit_dialog = new deposit_calc;
    deposit_dialog->show();
}

