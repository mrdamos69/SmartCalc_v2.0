#include "table.h"

#include "ui_table.h"

table::table(QWidget *parent) : QDialog(parent), ui(new Ui::table), count(1) {
  ui->setupUi(this);
  ui->tableWidget->setRowCount(count);
  ui->tableWidget->setColumnCount(5);
  ui->tableWidget->setHorizontalHeaderLabels(
      QStringList() << "Месяц"
                    << "Сумма платежа, руб."
                    << "Платеж по основному долгу, руб."
                    << "Платеж по процентам, руб."
                    << "Остаток долга, руб.");
  ui->tableWidget->setColumnWidth(1, 175);
  ui->tableWidget->setColumnWidth(2, 195);
  ui->tableWidget->setColumnWidth(3, 175);
  ui->tableWidget->setColumnWidth(4, 155);
}

table::~table() { delete ui; }

void table::check_calc() {
    if (check) this->anuitet_calc();
    else this->diferic_calc();
}

void table::anuitet_calc() {
    double result = 0, mec_procent = 0, mec_sum = 0, temp = sum_credit;
    for (int i = 0; i < size; i++, count++) {
        ui->tableWidget->setRowCount(count);
        double procent_year = (procent/100)/(size <= 12 ? size : 12);
        result = (sum_credit * procent_year * std::pow(1+procent_year, size)) / (std::pow(1+procent_year, size) - 1);
        mec_procent = temp * procent_year;
        mec_sum = result - mec_procent;
        temp-=mec_sum;
        this->add_table(result, mec_sum, mec_procent, temp);
    }
}

void table::diferic_calc() {
    double result = 0, mec_procent = 0, mec_sum = 0, temp = sum_credit;
    for (int i = 0; i < size; i++, count++) {
        ui->tableWidget->setRowCount(count);
        mec_procent = (temp*(procent/100))/(size <= 12 ? size : 12);
        mec_sum = sum_credit/size;
        result = mec_sum + mec_procent;
        temp-=(sum_credit/size);
        this->add_table(result, mec_sum, mec_procent, temp);
    }
}

void table::slot_all_sum(double all_sum) { this->sum_credit = all_sum; }
void table::slot_procent(double procent) { this->procent = procent; }
void table::slot_size_credit(int size_credit) { this->size = size_credit; }
void table::slot_data_credit(QDateTime data) { this->data_time = data; }
void table::slot_check(bool check) { this->check = check; }

void table::add_table(double result, double mec_sum, double mec_procent, double remains) {
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



