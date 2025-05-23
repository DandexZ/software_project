#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>

namespace Ui {
class Manager;
}

class Manager : public QWidget
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void on_SearchTransactions_clicked();

    void on_ChangePassword_clicked();

private:
    Ui::Manager *ui;
    //QString name,number;
};

#endif // MANAGER_H
