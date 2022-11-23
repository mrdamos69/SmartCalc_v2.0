#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

#include "../controller/controller.h"

namespace Ui {
class Graph;
}

namespace s21 {

class Graph : public QDialog {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  void print_graph();
  ~Graph();

 private:
  Ui::Graph *ui;
  s21::Controller contr_result;
  QString text;
  QString view_x;
  double xBegin, xEnd, X, h;

 public slots:
  void slot_text(QString text_calc);
  void slot_x(QString text_x);

 private slots:
  void on_spin_x_begin_valueChanged();
  void on_spin_x_end_valueChanged();
};

}  // namespace s21

#endif  // GRAPH_H
