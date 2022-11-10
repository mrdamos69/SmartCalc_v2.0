#include "credit_calc.h"
#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credit_calc)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, QSlider::valueChanged, this, credit_calc::on_horizontalSlider_actionTriggered);
    time_credit *= ui->comboBox->currentIndex();
}

credit_calc::~credit_calc() {
    delete ui;
}

void credit_calc::on_horizontalSlider_actionTriggered(int action) {
    ui->spinBox->setValue(action);
}

void credit_calc::on_pushButton_clicked() {
    new_table = new table;
    new_table->show();
}

void credit_calc::сalculation_credit() {

    QString q_result_credit = "";
    QString q_result_procent = "";

    result_procent = (((ui->spinBox->value()/100) * ui->doubleSpinBox->value()) / 12) * time_credit;

//    result_credit = (ui->spinBox->value()/time_credit) + (result_procent/time_credit);

//    q_result_credit = QString::number(result_credit);
    q_result_procent = QString::number(result_procent);

//    ui->label_all->setText(q_result_credit);
    ui->label_sum_pocent->setText(q_result_procent);

}

void credit_calc::on_pushButton_result_clicked() {
    this->сalculation_credit();
}

