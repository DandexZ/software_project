#include "usrwindow.h"
#include "ui_usrwindow.h"

#include "show_user.h"
#include "show_usr_money.h"

#include <QInputDialog>
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>

UsrWindow::UsrWindow(QWidget *parent,QString usrname) :
    QWidget(parent),
    ui(new Ui::UsrWindow),
    username(usrname),
    cardId(DatabaseManager::instance().getCardIdByStudentId(usrname)),
    name(DatabaseManager::instance().getNameByStudentId(usrname))
{
    ui->setupUi(this);
 //   QString name = DatabaseManager::instance().getNameByStudentId(usrname);
    QString money = DatabaseManager::instance().getBalanceByStudentId(usrname);
//    QString cardid = DatabaseManager::instance().getCardIdByStudentId(usrname);
    // 设置窗口标题
    this->setWindowTitle("AAA电脑维修 - 用户界面");
    this->setWindowIcon(QIcon(":/images/6.jpg"));


    ui->nameMessage->setText(name);//从数据库中选取信息输出 姓名、学号、余额
    ui->numberMessage->setText(usrname);
    ui->moneyMessage->setText(money);
    //设置图片
       QPixmap *pix = new QPixmap(":/images/2.jpg");
       QSize sz = ui->label_image->size();
       ui->label_image->setPixmap(pix->scaled(sz));

       //设置图片阴影效果
       QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
       shadow->setOffset(-3, 0);
       shadow->setColor(QColor("#888888"));
       shadow->setBlurRadius(30);
       ui->label_image->setGraphicsEffect(shadow);

}

UsrWindow::~UsrWindow()
{
    delete ui;
}

void UsrWindow::on_SearchTransactions_clicked()//点击查询流水
{
    //获取SQLite中的流水信息并输出：弹窗/新窗口
    show_usr_money* u =new show_usr_money(nullptr,cardId);
    u->show();
}


void UsrWindow::on_ChangePassword_clicked() //点击修改密码
{


        // 1. 获取并确认新密码
        QString newPassword = QInputDialog::getText(
            this,
            "修改密码",
            "请输入新密码：",
            QLineEdit::Password
        );
        if (newPassword.isEmpty()) return;

        QString confirmPassword = QInputDialog::getText(
            this,
            "修改密码",
            "请再次输入新密码：",
            QLineEdit::Password
        );
        if (newPassword != confirmPassword) {
            QMessageBox::warning(this, "错误", "两次输入的密码不一致！");
            return;
        }

        if (newPassword.length() < 6) {
            QMessageBox::warning(this, "错误", "密码长度至少6位！");
            return;
        }
        QString newname = name;
        if (newPassword.isEmpty()) return;
        //数据库修改密码的操作
        bool success = DatabaseManager::instance().modifyUserSelf(username,newname,newPassword);

        if(success)
        {
            QMessageBox::information(this, "修改成功", "用户修改成功！");
            ui->nameMessage->setText(newname);//从数据库中选取信息输出 姓名、学号、余额
            //this->close(); // 关闭注册窗口（可选）
        }
        else
        {
            QMessageBox::warning(this, "修改失败", "数据库修改失败，请重试！");
        }
}
