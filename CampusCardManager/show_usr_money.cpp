#include "show_usr_money.h"
#include "ui_show_usr_money.h"

show_usr_money::show_usr_money(QWidget *parent,QString cardid) :
    QWidget(parent),   
    ui(new Ui::show_usr_money),
    cardId(cardid)
{
    ui->setupUi(this);
    m = new QSqlTableModel;
    m->setTable("balance_change");
    m->setFilter(QString("card_id = '%1'").arg(cardId));
    ui->tableView->setModel(m);
    m->select();

    this->setWindowTitle("AAA电脑维修 - 展示流水");
    this->setWindowIcon(QIcon(":/images/8.jpg")); // 使用资源文件中的图标
}

show_usr_money::~show_usr_money()
{
    delete ui;
}
