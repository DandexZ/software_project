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
};

#endif // USRWINDOW_H
