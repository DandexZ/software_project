#include "new_user.h"
#include "ui_new_user.h"
#include<QMessageBox>

new_user::new_user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_user)
{
    ui->setupUi(this);
}

new_user::~new_user()
{
    delete ui;
}

void new_user::on_sureButton_clicked()
{
    QString Usernumber = ui->number->text();
    QString Username = ui->name->text();
    QString Usercard = ui->card->text();
    QString code1 = ui->code->text();
    QString code2 = ui->code_2->text();

    bool success = false;
    if(code1!=code2)
    {
        QMessageBox::warning(this, "注册失败", "两次输入的密码不一致!");
        ui->code_2->clear();
        ui->code_2->setFocus();
        return;
    }

//    if(DatabaseManager::instance().register_error(Usernumber,Usernumber,Usercard,code1)=="卡号重复")
//    {
//        QMessageBox::warning(this, "注册失败", "已存在输入的卡号!");
//        ui->card->clear();
//        ui->card->setFocus();
//        return;
//    }
//    else if(DatabaseManager::instance().register_error(Usernumber,Usernumber,Usercard,code1)=="学号重复" )
//    {
//        QMessageBox::warning(this, "注册失败", "已存在输入的学号!");
//        ui->number->clear();
//        ui->number->setFocus();
//        return;
//    }
//    else if(DatabaseManager::instance().register_error(Usernumber,Usernumber,Usercard,code1)=="密码重复")
//    {
//        QMessageBox::warning(this, "注册失败", "已存在输入的密码!");
//        ui->code->clear();
//        ui->code->setFocus();
//        return;
//    }
    //else
    //{
        success = DatabaseManager::instance().addUser(Usernumber, Username, Usercard, code1);
    //}

    if(success)
    {
        QMessageBox::information(this, "注册成功", "用户注册成功！");
        this->close(); // 关闭注册窗口（可选）
    }
    else
    {
        QMessageBox::warning(this, "注册失败", "数据库插入失败，请重试！");
    }

}
