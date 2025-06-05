#ifndef NEW_USER_H
#define NEW_USER_H

#include <QWidget>
#include "DatabaseManager.h"
namespace Ui {
class new_user;
}

class new_user : public QWidget
{
    Q_OBJECT

public:
    explicit new_user(QWidget *parent = nullptr);
    ~new_user();

private slots:
    void on_sureButton_clicked();

private:
    Ui::new_user *ui;
};

#endif // NEW_USER_H
