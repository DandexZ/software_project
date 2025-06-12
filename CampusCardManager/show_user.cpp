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

    this->setWindowTitle("AAA电脑维修 - 展示用户数据");
    this->setWindowIcon(QIcon(":/images/8.jpg")); // 使用资源文件中的图标
}

show_user::~show_user()
{
    delete ui;
}
