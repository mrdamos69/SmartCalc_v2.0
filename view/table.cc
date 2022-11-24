#include "table.h"

#include "ui_table.h"

s21::table::table(QWidget *parent)
    : QDialog(parent), ui(new Ui::table), count(1) {
  ui->setupUi(this);
  ui->tableWidget->setRowCount(count);
  ui->tableWidget->setColumnCount(5);
  ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                             << "Месяц"
                                             << "Сумма платежа, руб."
                                             << "Платеж по основному, руб."
                                             << "Платеж по процентам, руб."
                                             << "Остаток, руб.");
  ui->tableWidget->setColumnWidth(1, 175);
  ui->tableWidget->setColumnWidth(2, 195);
  ui->tableWidget->setColumnWidth(3, 175);
  ui->tableWidget->setColumnWidth(4, 155);
}

s21::table::~table() { delete ui; }

void s21::table::check_calc() {
  if (check && !check_deposit)
    this->anuitet_calc();
  else if (!check && !check_deposit)
    this->diferic_calc();
  else
    this->deposit_calc();
}

void s21::table::anuitet_calc() {
  double result = 0, month_procent = 0, month_sum = 0, remains = sum_credit;
  for (int i = 0; i < size; i++, count++) {
    ui->tableWidget->setRowCount(count);
    result = this->contr_table.anuitet_calc(sum_credit, procent, size,
                                            month_sum, month_procent, remains);
    this->add_table(result, month_sum, month_procent, remains);
  }
  this->result();
}

void s21::table::diferic_calc() {
  double result = 0, month_procent = 0, month_sum = 0, remains = sum_credit;
  for (int i = 0; i < size; i++, count++) {
    ui->tableWidget->setRowCount(count);
    result = this->contr_table.diferic_calc(sum_credit, procent, size,
                                            month_sum, month_procent, remains);
    this->add_table(result, month_sum, month_procent, remains);
  }
  this->result();
}

void s21::table::result() {
  double all_procent = 0;
  for (int i = 0; i < count - 1; i++) {
    all_procent += ui->tableWidget->item(i, 3)->text().toDouble();
  }
  ui->tableWidget->setRowCount(++count);
  item = new QTableWidgetItem("ИТОГО:");
  item_1 = new QTableWidgetItem(QString::number(all_procent));
  item_2 = new QTableWidgetItem(QString::number(all_procent + sum_credit));
  ui->tableWidget->setItem(count - 1, 2, item);
  ui->tableWidget->setItem(count - 1, 3, item_1);
  ui->tableWidget->setItem(count - 1, 4, item_2);
}

void s21::table::deposit_calc() {
  double result = 0, month_procent = 0, profit = sum_credit;
  for (int i = 0; i < size; i++, count++) {
    ui->tableWidget->setRowCount(count);
    //    result = this->contr_table.deposit_calc(add_sub_money, data_time,
    //    procent,
    //                                            month_procent, profit);

    this->add_table(result, profit - month_procent, month_procent, profit);
    this->contr_table.all_prifit(profit, result);
  }
  this->result();
}

void s21::table::slot_all_sum(double all_sum) { this->sum_credit = all_sum; }
void s21::table::slot_procent(double procent) { this->procent = procent; }
void s21::table::slot_size_credit(int size_credit) { this->size = size_credit; }
void s21::table::slot_data_credit(QDate data) { this->data_time = data; }
void s21::table::slot_check(bool check) { this->check = check; }
void s21::table::slot_check_deposit(bool check) { this->check_deposit = check; }
void s21::table::slot_add_sub_money(QVector<std::pair<QDate, double>> money) {
  this->add_sub_money = money;
}

void s21::table::add_table(double result, double mec_sum, double mec_procent,
                           double remains) {
  item = new QTableWidgetItem(data_time.toString("MM.yyyy"));
  item_1 = new QTableWidgetItem(QString::number(result));
  item_2 = new QTableWidgetItem(QString::number(mec_sum));
  item_3 = new QTableWidgetItem(QString::number(mec_procent));
  item_4 = new QTableWidgetItem(QString::number(remains > 1 ? remains : 0));

  ui->tableWidget->setItem(count - 1, 0, item);
  ui->tableWidget->setItem(count - 1, 1, item_1);
  ui->tableWidget->setItem(count - 1, 2, item_2);
  ui->tableWidget->setItem(count - 1, 3, item_3);
  ui->tableWidget->setItem(count - 1, 4, item_4);
  data_time = data_time.addMonths(1);
}
