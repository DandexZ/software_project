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
    //UsrWindow(QWidget *parent ,QString &db_path);QWidget *parent ,QString usrname
    UsrWindow(QWidget *parent ,QString usrname);
    ~UsrWindow();

private slots:
    void on_SearchTransactions_clicked();

    void on_ChangePassword_clicked();

    void on_ChangePassword_2_clicked();

private:
    Ui::UsrWindow *ui;
    QString username;
    QString cardId;
    QString name;
};

#endif // USRWINDOW_H
