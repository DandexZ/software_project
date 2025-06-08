#include "new_user.h"
#include "ui_new_user.h"
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>

new_user::new_user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_user)
{
    ui->setupUi(this);
    this->setWindowTitle("AAA电脑维修 - 注册界面");
    this->setWindowIcon(QIcon(":/images/7.jpg")); // 使用资源文件中的图标

    //设置图片
       QPixmap *pix = new QPixmap(":/images/5.jpg");
       QSize sz = ui->label_image->size();
       ui->label_image->setPixmap(pix->scaled(sz));

       //设置图片阴影效果
       QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
       shadow->setOffset(-3, 0);
       shadow->setColor(QColor("#888888"));
       shadow->setBlurRadius(30);
       ui->label_image->setGraphicsEffect(shadow);
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

    for(int i=0;i<Usernumber.size();i++)
    {
        if(Usernumber[i]<'0' || Usernumber[i] >'9')
        {
            QMessageBox::warning(this, "注册失败", "学号只能输入数字");
            ui->number->clear();
            ui->number->setFocus();
            return;
        }
    }

    for(int i=0;i<Usercard.size();i++)
    {
        if(Usercard[i]<'0' || Usercard[i] >'9')
        {
            QMessageBox::warning(this, "注册失败", "卡号只能输入数字");
            ui->card->clear();
            ui->card->setFocus();
            return;
        }
    }

    if(code1!=code2)
    {
        QMessageBox::warning(this, "注册失败", "两次输入的密码不一致!");
        ui->code_2->clear();
        ui->code_2->setFocus();
        return;
    }

    if(code1.size()<6)
    {
        QMessageBox::warning(this, "注册失败", "密码长度不少于6位!");
        ui->code->clear();
        ui->code->setFocus();
        ui->code_2->clear();
        ui->code_2->setFocus();
        return;
    }

    if(DatabaseManager::instance().register_error(Usernumber,Username,Usercard,code1)=="卡号重复")
    {
        QMessageBox::warning(this, "注册失败", "已存在输入的卡号!");
        ui->card->clear();
        ui->card->setFocus();
        return;
    }
    else if(DatabaseManager::instance().register_error(Usernumber,Username,Usercard,code1)=="学号重复" )
    {
        QMessageBox::warning(this, "注册失败", "已存在输入的学号!");
        ui->number->clear();
        ui->number->setFocus();
        return;
    }
    else if(DatabaseManager::instance().register_error(Usernumber,Username,Usercard,code1)=="密码重复")
    {
        QMessageBox::warning(this, "注册失败", "已存在输入的密码!");
        ui->code->clear();
        ui->code->setFocus();
        ui->code_2->clear();
        ui->code_2->setFocus();
        return;
    }
    else
    {
        success = DatabaseManager::instance().addUser(Usernumber, Username, Usercard, code1);
    }

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
