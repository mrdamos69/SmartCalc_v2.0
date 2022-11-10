#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include "../controller/controller.h"

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    void print_graph();
    ~Graph();

private:
    Ui::Graph *ui;
    Controller contr_result;
    QString text;
    QString view_x;
    double xBegin, xEnd, h, X, xy_1, xy_2, result_1, result_2;
    int N;
    QVector<double> x, y;

public slots:
    void slot_text(QString text_calc);
    void slot_x(QString text_x);
private slots:
    void on_spin_xy_1_valueChanged();
    void on_spin_xy_2_valueChanged();
    void on_spin_result_1_valueChanged();
    void on_spin_result_2_valueChanged();
};

#endif // GRAPH_H
