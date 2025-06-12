#include "manager.h"
#include "ui_manager.h"
#include "new_user.h"
#include "show_user.h"
#include "show_money.h"
#include "mainwindow.h"
#include <QInputDialog>
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>

Manager::Manager(QWidget *parent,QString usrname) :
    QWidget(parent),ui(new Ui::Manager),username(usrname)
{
    ui->setupUi(this);
    QString name = DatabaseManager::instance().getAdminNameById(usrname);
    ui->name_label->setText(name);

    // 设置窗口标题
    this->setWindowTitle("AAA电脑维修 - 管理员界面");
    this->setWindowIcon(QIcon(":/images/6.jpg")); // 使用资源文件中的图标

    //设置图片
       QPixmap *pix = new QPixmap(":/images/3.jpg");
       QSize sz = ui->label_image->size();
       ui->label_image->setPixmap(pix->scaled(sz));

       //设置图片阴影效果
       QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
       shadow->setOffset(-3, 0);
       shadow->setColor(QColor("#888888"));
       shadow->setBlurRadius(30);
       ui->label_image->setGraphicsEffect(shadow);

}

Manager::~Manager()
{
    delete ui;
}

void Manager::on_ChangePassword_clicked()
{
    // 1. 弹出输入对话框获取旧密码、新密码和确认密码
      bool ok;
      QString oldPassword = QInputDialog::getText(
          this,
          "修改密码",
          "请输入旧密码：",
          QLineEdit::Password,
          "",
          &ok
      );

      if (!ok || oldPassword.isEmpty()) {
          return;  // 用户取消或未输入
      }

      QString newPassword = QInputDialog::getText(
          this,
          "修改密码",
          "请输入新密码：",
          QLineEdit::Password,
          "",
          &ok
      );

      if (!ok || newPassword.isEmpty()) {
          return;
      }

      if(newPassword.size()<6)
      {
          QMessageBox::warning(this, "注册失败", "密码长度不少于6位!");
          return;
      }

      QString confirmPassword = QInputDialog::getText(
          this,
          "修改密码",
          "请再次输入新密码：",
          QLineEdit::Password,
          "",
          &ok
      );

      if (!ok || confirmPassword.isEmpty()) {
          return;
      }

      // 2. 检查两次输入的新密码是否一致
      if (newPassword != confirmPassword) {
          QMessageBox::warning(this, "错误", "两次输入的新密码不一致！");
          return;
      }

      //数据库修改密码的操作
      bool success = DatabaseManager::instance().modifyadminSelf(username,newPassword);

      if(success)
      {
          QMessageBox::information(this, "修改成功", "用户修改成功！");
          //this->close(); // 关闭注册窗口（可选）
      }
      else
      {
          QMessageBox::warning(this, "修改失败", "数据库修改失败，请重试！");
      }
}

void Manager::on_Sign_up_clicked()
{
    new_user *u = new new_user;
    u->show();
}

void Manager::on_destroy_user_clicked()
{
      bool ok;
      QString Id = QInputDialog::getText(
          this,
          "注销用户",
          "请输入待注销用户的学号：",
          QLineEdit::Normal,
          "",
          &ok
      );

      if (!ok || Id.isEmpty()) {
          return;  // 用户取消或未输入
      }

      QString cardid = DatabaseManager::instance().getCardIdByStudentId(Id);
      bool success = DatabaseManager::instance().deleteUser(cardid);

      if(success)
      {
          QMessageBox::information(this, "注销成功", "用户注销成功！");
          //this->close(); // 关闭注册窗口（可选）
      }
      else
      {
          QMessageBox::warning(this, "注销失败", "数据库删除失败，请重试！");
      }
}

void Manager::on_increase_money_clicked()
{
    bool ok;
    QString update_id = QInputDialog::getText(
        this,
        "充值余额",
        "请输入待充值的用户的学号",
        QLineEdit::Normal,
        "",
        &ok
    );

    if (!ok || update_id.isEmpty()) {
        return;  // 用户取消或未输入
    }

    QString update_money = QInputDialog::getText(
        this,
        "充值余额",
        "请输入待充值的用户的余额",
        QLineEdit::Normal,
        "",
        &ok
    );

    if (!ok || update_money.isEmpty()) {
        return;  // 用户取消或未输入
    }

    QString cardid = DatabaseManager::instance().getCardIdByStudentId(update_id);
    double money = update_money.toDouble();
    if(money < 0)
    {
        QMessageBox::warning(this, "更新失败", "输入数据有误！");
        return;
    }
    bool success = DatabaseManager::instance().updateBalance(cardid,money);

    if(success)
    {
        QMessageBox::information(this, "更新成功", "用户更新成功！");
        //this->close(); // 关闭注册窗口（可选）
    }
    else
    {
        QMessageBox::warning(this, "更新失败", "数据库更新失败，请重试！");
    }

}

void Manager::on_userdb_clicked()
{
    show_user* u =new show_user;
    u->show();
}

void Manager::on_moneydb_clicked()
{
    show_money* u=new show_money;
    u->show();
}

void Manager::on_decrease_money_clicked()
{
    bool ok;
    QString update_id = QInputDialog::getText(
        this,
        "消费余额",
        "请输入待消费的用户的学号",
        QLineEdit::Normal,
        "",
        &ok
    );

    if (!ok || update_id.isEmpty()) {
        return;  // 用户取消或未输入
    }

    QString update_money = QInputDialog::getText(
        this,
        "消费余额",
        "请输入待消费的用户的余额",
        QLineEdit::Normal,
        "",
        &ok
    );

    if (!ok || update_money.isEmpty()) {
        return;  // 用户取消或未输入
    }

    QString cardid = DatabaseManager::instance().getCardIdByStudentId(update_id);
    double money = update_money.toDouble();
    if(money < 0)
    {
        QMessageBox::warning(this, "更新失败", "输入数据有误！");
        return;
    }
    money = -money;
    bool success = DatabaseManager::instance().updateBalance(cardid,money);

    if(success)
    {
        QMessageBox::information(this, "更新成功", "用户更新成功！");
        //this->close(); // 关闭注册窗口（可选）
    }
    else
    {
        QMessageBox::warning(this, "更新失败", "数据库更新失败，请重试！");
    }
}

void Manager::on_Exit_clicked()
{
    this->close();
    MainWindow *main = new MainWindow();
    main->show();
}

