#ifndef SHOW_USER_H
#define SHOW_USER_H

#include <QWidget>
#include<DatabaseManager.h>
#include<QSqlTableModel>

namespace Ui {
class show_user;
}

class show_user : public QWidget
{
    Q_OBJECT

public:
    explicit show_user(QWidget *parent = nullptr);
 //   show_user(QWidget *parent ,QString cardId);
    ~show_user();

private slots:

private:
    Ui::show_user *ui;
    QSqlTableModel *m;
  //  QString cardId;
};

#endif // SHOW_USER_H
