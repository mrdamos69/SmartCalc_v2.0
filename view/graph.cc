#include "graph.h"

#include "ui_graph.h"

s21::Graph::Graph(QWidget* parent)
    : QDialog(parent), ui(new Ui::Graph), xBegin(0), xEnd(0), h(0.1) {
  ui->setupUi(this);
}

s21::Graph::~Graph() { delete ui; }

void s21::Graph::slot_text(QString text_calc) { this->text = text_calc; }

void s21::Graph::slot_x(QString text_x) { this->view_x = text_x; }

void s21::Graph::print_graph() {
  ui->widget->clearGraphs();
  xBegin = xEnd = 0;
  ui->widget->xAxis->setRange(ui->spin_x_begin->text().toDouble(),
                              ui->spin_x_end->text().toDouble());
  ui->widget->yAxis->setRange(ui->spin_y_begin->text().toDouble(),
                              ui->spin_y_end->text().toDouble());

  if (view_x == "") {
    xBegin = ui->spin_y_begin->text().toInt();
    xEnd = ui->spin_y_end->text().toInt() + h;
  } else {
    xBegin = std::abs(view_x.toDouble());
    xEnd = view_x.toDouble() + h;
    ui->widget->xAxis->setRange(xBegin, xEnd);
    ui->widget->yAxis->setRange(xBegin, xEnd);
    ui->spin_x_begin->setValue(xBegin);
    ui->spin_x_end->setValue(xEnd);
  }

  auto coordinates = contr_result.print_graph(xBegin, xEnd, text);

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(coordinates.first, coordinates.second);
  ui->widget->replot();
}
