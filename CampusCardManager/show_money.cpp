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

    this->setWindowTitle("AAA电脑维修 - 展示用户数据");
    this->setWindowIcon(QIcon(":/images/8.jpg")); // 使用资源文件中的图标
}

show_money::~show_money()
{
    delete ui;
}
