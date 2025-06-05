#ifndef UPDATE_USERBYMANAGER_H
#define UPDATE_USERBYMANAGER_H

#include <QWidget>

namespace Ui {
class update_userBymanager;
}

class update_userBymanager : public QWidget
{
    Q_OBJECT

public:
    explicit update_userBymanager(QWidget *parent = nullptr);
    ~update_userBymanager();

private:
    Ui::update_userBymanager *ui;
};

#endif // UPDATE_USERBYMANAGER_H
