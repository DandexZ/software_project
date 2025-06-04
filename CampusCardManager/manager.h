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
    Manager(QWidget *parent ,QString &db_path);
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void on_SearchTransactions_clicked();

    void on_ChangePassword_clicked();

private:
    Ui::Manager *ui;
};

#endif // MANAGER_H
