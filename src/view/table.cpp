#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(12);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                               << "Месяц" << "Сумма платежа, руб."
                                               << "Платеж по основному долгу, руб."
                                               << "Платеж по процентам, руб."
                                               << "Остаток долга, руб.");
    ui->tableWidget->setColumnWidth(1, 175);
    ui->tableWidget->setColumnWidth(2, 195);
    ui->tableWidget->setColumnWidth(3, 175);
}

table::~table() {
    delete ui;
}
