#include "deposit_calc.h"

#include "ui_deposit_calc.h"

deposit_calc::deposit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::deposit_calc) {
  ui->setupUi(this);

  ui->tableWidget->setRowCount(0);
  ui->tableWidget->setColumnCount(1);
  ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                             << "Сумма пополнения");
  ui->tableWidget->setColumnWidth(0, 265);

  ui->tableWidget_2->setRowCount(0);
  ui->tableWidget_2->setColumnCount(1);
  ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()
                                               << "Сумма списания");
  ui->tableWidget_2->setColumnWidth(0, 265);

  connect(ui->horizontalSlider, QSlider::valueChanged, this,
          deposit_calc ::on_horizontalSlider_actionTriggered);
}

deposit_calc::~deposit_calc() { delete ui; }

void deposit_calc::on_horizontalSlider_actionTriggered(int action) {
  ui->spinBox_sum->setValue(action);
}

void deposit_calc::on_add_money_clicked() {
  QTableWidgetItem *item =
      new QTableWidgetItem(QString::number(ui->spinBox_add->value()));
  ui->tableWidget->setRowCount(++rows);
  ui->tableWidget->setItem(this->rows - 1, 0, item);
  ui->tableWidget->update();
}

void deposit_calc::on_sub_money_clicked() {
  ui->tableWidget->setRowCount(--rows);
}

void deposit_calc::on_add_money_2_clicked() {
  QTableWidgetItem *item =
      new QTableWidgetItem(QString::number(ui->spinBox_sub->value()));
  ui->tableWidget_2->setRowCount(++rows_2);
  ui->tableWidget_2->setItem(this->rows_2 - 1, 0, item);
  ui->tableWidget_2->update();
}

void deposit_calc::on_sub_money_2_clicked() {
  ui->tableWidget_2->setRowCount(--rows_2);
}
