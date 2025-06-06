#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include<DatabaseManager.h>
#include<QSqlTableModel>
namespace Ui {
class Manager;
}

class Manager : public QWidget
{
    Q_OBJECT

public:
    Manager(QWidget *parent ,QString usrname);
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:

    void on_ChangePassword_clicked();

    void on_Sign_up_clicked();

    void on_destroy_user_clicked();

    void on_increase_money_clicked();

    void on_userdb_clicked();

    void on_moneydb_clicked();

    void on_decrease_money_clicked();

private:
    Ui::Manager *ui;
    QString username;
};

#endif // MANAGER_H
