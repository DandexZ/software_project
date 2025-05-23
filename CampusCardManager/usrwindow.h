#ifndef USRWINDOW_H
#define USRWINDOW_H

#include <QWidget>


namespace Ui {
class UsrWindow;
}

class UsrWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UsrWindow(QWidget *parent = nullptr);
    ~UsrWindow();

private slots:
    void on_SearchTransactions_clicked();

    void on_ChangePassword_clicked();

private:
    Ui::UsrWindow *ui;
//    QString name,number,money;
};

#endif // USRWINDOW_H
