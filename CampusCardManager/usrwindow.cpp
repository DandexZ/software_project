#include "usrwindow.h"
#include "ui_usrwindow.h"
#include <QInputDialog>
#include<QMessageBox>

UsrWindow::UsrWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsrWindow)
{
    ui->setupUi(this);
//    ui->nameMessage->setText(name);//从数据库中选取信息输出 姓名、学号、余额
//    ui->numberMessage->setText(number);
//    ui->moneyMessage->setText(money);
    ui->nameMessage->setText("宫毓希");//从数据库中选取信息输出 姓名、学号、余额
    ui->numberMessage->setText("2022");
    ui->moneyMessage->setText("1000000");
}

UsrWindow::~UsrWindow()
{
    delete ui;
}

void UsrWindow::on_SearchTransactions_clicked()//点击查询流水
{
    //获取SQLite中的流水信息并输出：弹窗/新窗口
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
}
