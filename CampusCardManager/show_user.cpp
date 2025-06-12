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

   //允许使用回车表示确定
    connect(ui->lineEdit, &QLineEdit::returnPressed, ui->pushButton, &QPushButton::click);
}

show_user::~show_user()
{
    delete ui;
}

void show_user::on_pushButton_clicked()
{
    QString keyword = ui->lineEdit->text();
    bool all = false;
        if (keyword.isEmpty()) {
            QMessageBox::warning(this, "提示", "没输入信息，默认显示全部信息");
            all = true;
        }
        if(all)
        {
            m->setTable("users");
            ui->tableView->setModel(m);
            m->select();
        }
        else
        {
            // 构建模糊查询条件
            QString filter = QString("student_id LIKE '%%1%' OR "
                                     "name LIKE '%%1%' OR "
                                     "card_id LIKE '%%1%' OR "
                                     "password LIKE '%%1%' OR "
                                     "balance LIKE '%%1%'").arg(keyword);

            m->setFilter(filter);
            if (!m->select())
            {
                QMessageBox::warning(this, "错误", "查询失败");
            }
        }
}
