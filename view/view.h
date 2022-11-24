#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "../controller/controller.h"
#include "credit_calc.h"
#include "deposit_calc.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class View : public QMainWindow {
  Q_OBJECT

public:
  View(QWidget *parent = nullptr);
  ~View();

private slots:
  void digits_numbers();
  void digits_operations();
  void clean_result();
  void on_pushButton_L_clicked();
  void on_pushButton_R_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_cos_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_mult_clicked();
  void on_pushButton_plus_clicked();
  void on_pushButton_pow_clicked();
  void on_pushButton_result_clicked();
  void on_pushButton_sin_clicked();
  void on_pushButton_sin_2_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_sub_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_tch_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_credit_calc_clicked();
  void on_pushButton_deposit_calc_clicked();

private:
  Ui::View *ui;
  s21::Graph *graph_func;
  s21::credit_calc *calc_dialog;
  s21::deposit_calc *deposit_dialog;
  s21::Controller contr_result;
  bool clean_view;

signals:
  void signal_text(QString);
  void signal_x(QString);
};

} // namespace s21
#endif // VIEW_H
