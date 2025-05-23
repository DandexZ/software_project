#include "manager.h"
#include "ui_manager.h"
#include <QInputDialog>
#include<QMessageBox>

Manager::Manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
//    ui->nameMessage->setText(name);//从数据库中选取信息输出 姓名、学号、余额
//    ui->numberMessage->setText(number);
}

Manager::~Manager()
{
    delete ui;
}

void Manager::on_SearchTransactions_clicked()
{

}

void Manager::on_ChangePassword_clicked()
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
