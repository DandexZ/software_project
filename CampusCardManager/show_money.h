#ifndef SHOW_MONEY_H
#define SHOW_MONEY_H

#include <QWidget>
#include<DatabaseManager.h>
#include<QSqlTableModel>


namespace Ui {
class show_money;
}

class show_money : public QWidget
{
    Q_OBJECT

public:
    explicit show_money(QWidget *parent = nullptr);
    ~show_money();

private:
    Ui::show_money *ui;
    QSqlTableModel *m;
};

#endif // SHOW_MONEY_H
