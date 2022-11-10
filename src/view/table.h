#ifndef TABLE_H
#define TABLE_H

#include <QDialog>

namespace Ui {
class table;
}

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = nullptr);
    ~table();

private:
    Ui::table *ui;
    QString data;
    int sum_credit;
    int sum_procent;
    int sum_output;
};

#endif // TABLE_H
