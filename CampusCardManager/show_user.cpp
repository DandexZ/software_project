#include "show_user.h"
#include "ui_show_user.h"

show_user::show_user(QWidget *parent):
    QWidget(parent),ui(new Ui::show_user)
{
    ui->setupUi(this);

    m = new QSqlTableModel;
    m->setTable("users");
    ui->tableView->setModel(m);
    m->select();
}

show_user::~show_user()
{
    delete ui;
}
