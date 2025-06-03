#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<DatabaseManager.h>
#include<QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent,QString &db_path);
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //wjq
    DatabaseManager& m_dbManager;  // 数据库管理器引用
       QSqlTableModel* m_usersModel;  // 用户表格模型
       QString dbpath;
     // wjq
};
#endif // MAINWINDOW_H
