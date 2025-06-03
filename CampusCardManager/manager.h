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
    //wjq
    DatabaseManager& m_dbManager;  // 数据库管理器引用
       QSqlTableModel* m_usersModel;  // 用户表格模型
       QString dbpath;
      // wjq
    //QString name,number;
};

#endif // MANAGER_H
