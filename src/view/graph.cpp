#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph) {
    ui->setupUi(this);
}

void Graph::slot_text(QString text_calc) {
    this->text = text_calc;
}

void Graph::slot_x(QString text_x) {
    this->view_x = text_x;
}

void Graph::print_graph() {
    QByteArray ba = text.toLocal8Bit();
    char* buf = ba.data();
    ui->widget->clearGraphs();
    x.clear();
    y.clear();
    xBegin = xEnd = 0;
    h = 0.1;

    xBegin = ui->spin_result_2->text().toInt();
    xEnd = ui->spin_result_1->text().toInt() + h;

    ui->widget->xAxis->setRange(ui->spin_xy_2->text().toDouble(), ui->spin_xy_1->text().toDouble());
    ui->widget->yAxis->setRange(ui->spin_xy_2->text().toDouble(), ui->spin_xy_1->text().toDouble());
    N = (xEnd - xBegin)/h + 2;

    for (X = xBegin; X <= xEnd; X+=h) {
        x.push_back(X);
        y.push_back(contr_result.input_calc(buf, X));
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

Graph::~Graph() {
    delete ui;
}

void Graph::on_spin_xy_1_valueChanged() {
    this->print_graph();
}

void Graph::on_spin_xy_2_valueChanged() {
    this->print_graph();
}

void Graph::on_spin_result_1_valueChanged() {
    this->print_graph();
}

void Graph::on_spin_result_2_valueChanged() {
    this->print_graph();
}
