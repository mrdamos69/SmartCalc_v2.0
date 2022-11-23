#include "deposit_calc.h"

#include "ui_deposit_calc.h"

s21::deposit_calc::deposit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::deposit_calc), new_table(nullptr) {
  ui->setupUi(this);

  ui->tableWidget->setRowCount(0);
  ui->tableWidget->setColumnCount(2);
  ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                             << "Дата"
                                             << "Сумма пополнения");
  ui->tableWidget->setColumnWidth(0, 115);
  ui->tableWidget->setColumnWidth(1, 135);

  ui->tableWidget_2->setRowCount(0);
  ui->tableWidget_2->setColumnCount(2);
  ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()
                                               << "Дата"
                                               << "Сумма списания");
  ui->tableWidget_2->setColumnWidth(0, 115);
  ui->tableWidget_2->setColumnWidth(1, 135);
}

s21::deposit_calc::~deposit_calc() {
  if (new_table != nullptr) {
    delete new_table;
    new_table = nullptr;
  }
  delete ui;
}

void s21::deposit_calc::on_horizontalSlider_actionTriggered(int action) {
  ui->spinBox_sum->setValue(action);
}

void s21::deposit_calc::on_add_money_clicked() {
  QTableWidgetItem *item =
      new QTableWidgetItem(QString::number(ui->spinBox_add->value()));
  QTableWidgetItem *item_2 =
      new QTableWidgetItem(ui->dateEdit_add->date().toString("MM.yyyy"));
  ui->tableWidget->setRowCount(++rows);
  ui->tableWidget->setItem(this->rows - 1, 1, item);
  ui->tableWidget->setItem(this->rows - 1, 0, item_2);
  this->contr_deposit.push_line_table(add_sub_money, ui->dateEdit_sub->date(),
                                      ui->spinBox_sub->value());
}

void s21::deposit_calc::on_sub_money_clicked() {
  if (rows > 0) {
    ui->tableWidget->setRowCount(--rows);
    add_sub_money.pop_front();
  }
}

void s21::deposit_calc::on_add_money_2_clicked() {
  double buffer = 0;
  for (auto value : add_sub_money) {
    if (value.second < 0) buffer -= value.second;
  }
  if ((ui->spinBox_sum->value() - buffer >= ui->spinBox_sub->value())) {
    QTableWidgetItem *item =
        new QTableWidgetItem(QString::number(ui->spinBox_sub->value() * (-1)));
    QTableWidgetItem *item_2 =
        new QTableWidgetItem(ui->dateEdit_sub->date().toString("MM.yyyy"));
    ui->tableWidget_2->setRowCount(++rows_2);
    ui->tableWidget_2->setItem(this->rows_2 - 1, 1, item);
    ui->tableWidget_2->setItem(this->rows_2 - 1, 0, item_2);
    this->contr_deposit.push_line_table(add_sub_money, ui->dateEdit_sub->date(),
                                        ui->spinBox_sub->value() * (-1));
  }
}

void s21::deposit_calc::on_sub_money_2_clicked() {
  if (rows_2 > 0) {
    ui->tableWidget_2->setRowCount(--rows_2);
    add_sub_money.pop_front();
  }
}

void s21::deposit_calc::on_pushButton_clicked() {
  this->refresh();
  emit signal_all_sum(ui->spinBox_sum->value());
  emit signal_procent(ui->doubleSpinBox->value());
  emit signal_size((ui->comboBox->currentIndex() + 1) * 12);
  emit signal_data(ui->dateEdit->date());
  emit signal_check(true);
  emit signal_add_sub_money(add_sub_money);
  new_table->check_calc();
  new_table->show();
}

void s21::deposit_calc::refresh() {
  if (new_table != nullptr) {
    delete new_table;
    new_table = nullptr;
  }
  new_table = new table;
  connect(this, &deposit_calc::signal_all_sum, new_table, &table::slot_all_sum);
  connect(this, &deposit_calc::signal_procent, new_table, &table::slot_procent);
  connect(this, &deposit_calc::signal_size, new_table,
          &table::slot_size_credit);
  connect(this, &deposit_calc::signal_data, new_table,
          &table::slot_data_credit);
  connect(this, &deposit_calc::signal_check, new_table,
          &table::slot_check_deposit);
  connect(this, &deposit_calc::signal_add_sub_money, new_table,
          &table::slot_add_sub_money);
}

void s21::deposit_calc::on_horizontalSlider_valueChanged(int value) {
  ui->spinBox_sum->setValue(value + 10000);
}
