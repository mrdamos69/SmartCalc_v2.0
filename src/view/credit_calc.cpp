#include "credit_calc.h"

#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::credit_calc), time_credit(0), this_annuetet(false) {
  ui->setupUi(this);
  connect(ui->horizontalSlider, QSlider::valueChanged, this,
          credit_calc::on_horizontalSlider_actionTriggered);
}

credit_calc::~credit_calc() {
  delete new_table;
  delete ui;
}

void credit_calc::on_horizontalSlider_actionTriggered(int action) {
  ui->spinBox->setValue(action);
}

void credit_calc::on_pushButton_clicked() {
  time_credit = (ui->comboBox->currentIndex() + 1) * 12;
  this->refresh();
  emit signal_all_sum(ui->spinBox->value());
  emit signal_procent(ui->doubleSpinBox->value());
  emit signal_size_credit(time_credit);
  emit signal_data_credit(ui->dateEdit->dateTime());
  emit signal_check(this_annuetet);

  new_table->check_calc();
  new_table->show();
}

void credit_calc::on_differenc_calc_clicked(bool check) {
    if (check) this->this_annuetet = false;
    this->refresh();
}

void credit_calc::on_annyitet_calc_clicked(bool check) {
    if (check) this->this_annuetet = true;
    this->refresh();
}

void credit_calc::refresh() {
    if (new_table == nullptr) delete new_table;
    new_table = new table;
    connect(this, &credit_calc::signal_all_sum, new_table, &table::slot_all_sum);
    connect(this, &credit_calc::signal_procent, new_table,
            &table::slot_procent);
    connect(this, &credit_calc::signal_size_credit, new_table,
            &table::slot_size_credit);
    connect(this, &credit_calc::signal_data_credit, new_table,
            &table::slot_data_credit);
    connect(this, &credit_calc::signal_check, new_table,
            &table::slot_check);
}
