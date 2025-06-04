#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usrwindow.cpp"
#include "manager.h"
#include <QSqlDatabase>
#include <QDebug>
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->hide();  // 移除状态栏
    connect(ui->input_code, &QLineEdit::returnPressed, ui->pushButton, &QPushButton::click);

    //设置图片
       QPixmap *pix = new QPixmap(":/images/1.png");
       QSize sz = ui->label_image->size();
       ui->label_image->setPixmap(pix->scaled(sz));

       //设置图片阴影效果
       QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
       shadow->setOffset(-3, 0);
       shadow->setColor(QColor("#888888"));
       shadow->setBlurRadius(30);
       ui->label_image->setGraphicsEffect(shadow);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //获取登录名和密码
    QString usrname = ui->input_usr->text();
    QString password = ui->input_code->text();
    qDebug("%s ",qPrintable(usrname));
    qDebug("%s ",qPrintable(password));

    // 验证输入是否为空 顺便判断是管理员的账号还是学生的账号
    if(usrname.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名或密码不能为空!");
        return;
    }


   bool loginSuccess1 = false,loginSuccess2 = false;
    // 查询用户是否存在
    if(password==DatabaseManager::instance().getadmin_password(usrname)){ loginSuccess1 = true;}//学生密码对
    if(password==DatabaseManager::instance().getusr_password(usrname)){ loginSuccess2 = true;}//管理员密码对

    if(!loginSuccess1 && !loginSuccess2) {//密码错误
        QMessageBox::warning(this, "登录失败", "用户名或密码错误!");
        ui->input_code->clear();
        ui->input_code->setFocus();
        return;
    }

    if(loginSuccess2){
        UsrWindow *usr = new UsrWindow(nullptr);
        usr->show();  // 显示新窗口
        // 建议设置：当新窗口关闭时自动释放内存
        usr->setAttribute(Qt::WA_DeleteOnClose);
    }
    if(loginSuccess1)
    {
        Manager *manager=new Manager(nullptr);
        manager->show();
        manager->setAttribute(Qt::WA_DeleteOnClose);
    }

    this->close();       // 关闭登录窗口
}

