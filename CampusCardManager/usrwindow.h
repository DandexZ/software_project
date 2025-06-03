#ifndef USRWINDOW_H
#define USRWINDOW_H

#include <QWidget>
#include<DatabaseManager.h>
#include<QSqlTableModel>

namespace Ui {
class UsrWindow;
}

class UsrWindow : public QWidget
{
    Q_OBJECT

public:
    UsrWindow(QWidget *parent ,QString &db_path);
    explicit UsrWindow(QWidget *parent = nullptr);
    ~UsrWindow();

private slots:
    void on_SearchTransactions_clicked();

    void on_ChangePassword_clicked();

private:
    Ui::UsrWindow *ui;
    //wjq
    DatabaseManager& m_dbManager;  // 数据库管理器引用
       QSqlTableModel* m_usersModel;  // 用户表格模型
       QString dbpath;
      // wjq
//    QString name,number,money;
};

#endif // USRWINDOW_H
