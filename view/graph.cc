#include "graph.h"

#include "ui_graph.h"

s21::Graph::Graph(QWidget *parent)
    : QDialog(parent), ui(new Ui::Graph), xBegin(0), xEnd(0), h(0.1) {
  ui->setupUi(this);
}

s21::Graph::~Graph() { delete ui; }

void s21::Graph::slot_text(QString text_calc) {
  this->text = text_calc.toStdString();
}

void s21::Graph::slot_x(QString text_x) { this->view_x = text_x; }

void s21::Graph::print_graph() {
  ui->widget->clearGraphs();
  xBegin = xEnd = 0;
  ui->widget->xAxis->setRange(15, 15);
  ui->widget->yAxis->setRange(15, 15);

  if (view_x == "") {
    xBegin = ui->spin_x_begin->text().toInt();
    xEnd = ui->spin_x_end->text().toInt();
  } else {
    xBegin = view_x.toDouble() * (-1);
    xEnd = view_x.toDouble();
  }
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(xBegin, xEnd);
  ui->spin_x_begin->setValue(xBegin);
  ui->spin_x_end->setValue(xEnd);
  auto coordinates = this->add_coordinates(xBegin, xEnd);
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(coordinates.first, coordinates.second);
  ui->widget->replot();
}

std::pair<QVector<double>, QVector<double>>
s21::Graph::add_coordinates(const double &xBegin, const double &xEnd) {
  QVector<double> x, y;
  for (double i = xBegin; i <= xEnd; i += 0.1) {
    x.push_back(i);
    y.push_back(contr_result.input_calc(text, i));
  }
  return std::pair<QVector<double>, QVector<double>>(x, y);
}

void s21::Graph::on_spin_x_begin_valueChanged() { this->print_graph(); }

void s21::Graph::on_spin_x_end_valueChanged() { this->print_graph(); }
