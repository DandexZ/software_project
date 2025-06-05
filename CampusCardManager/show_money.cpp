#include "show_money.h"
#include "ui_show_money.h"

show_money::show_money(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::show_money)
{
    ui->setupUi(this);
    m = new QSqlTableModel;
    m->setTable("balance_change");
    ui->tableView->setModel(m);
    m->select();

}

show_money::~show_money()
{
    delete ui;
}
