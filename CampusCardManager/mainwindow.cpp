#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usrwindow.cpp"
#include "manager.h"
#include <QSqlDatabase>
#include <QDebug>
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->hide();  // 移除状态栏
    connect(ui->input_code, &QLineEdit::returnPressed, ui->pushButton, &QPushButton::click);

    //设置图片
       QPixmap *pix = new QPixmap(":/1.png");
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

    // 验证输入是否为空 顺便判断是管理员的账号还是学生的账号
    if(usrname.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名或密码不能为空!");
        return;
    }

    // 打开SQLite数据库

    // 查询用户是否存在

    //用户不存在

    //用户存在验证密码是否正确

    // 模拟验证成功
    bool loginSuccess = true;

    if(!loginSuccess) {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误!");
        ui->input_code->clear();
        ui->input_code->setFocus();
        return;
    }

    //role INTEGER
    //if若用户是学生，获得姓名、学号、金额并传入UsrWinodw
    UsrWindow *usr = new UsrWindow();
    usr->show();  // 显示新窗口
    //else若用户是管理员，获得姓名、ID，并传入manager
//    Manager* manager= new Manager();
//    manager->show();

    this->close();       // 关闭登录窗口

    // 建议设置：当新窗口关闭时自动释放内存
    usr->setAttribute(Qt::WA_DeleteOnClose);
}
