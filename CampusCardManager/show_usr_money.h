#ifndef SHOW_USR_MONEY_H
#define SHOW_USR_MONEY_H

#include <QWidget>
#include<DatabaseManager.h>
#include<QSqlTableModel>
namespace Ui {
class show_usr_money;
}

class show_usr_money : public QWidget
{
    Q_OBJECT

public:
    show_usr_money(QWidget *parent ,QString cardId);
    explicit show_usr_money(QWidget *parent = nullptr);

    ~show_usr_money();

private:
    Ui::show_usr_money *ui;
    QSqlTableModel *m;
    QString cardId;
};

#endif // SHOW_USR_MONEY_H
