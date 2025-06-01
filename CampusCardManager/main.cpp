#include "mainwindow.h"
#include "DatabaseManager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString dbPath = QCoreApplication::applicationDirPath() + "/../../CampusCardManager/database/data.db";
    //QString dbPath = " E:\\softwork\\soft_work1\\software_project\\CampusCardManager\\database";
    qDebug()<<"请检查数据库是否在 "<<dbPath;
    DatabaseManager m(dbPath);

//zhr测试数据库语句

    // 添加用户
    if (m.addUser("20230101", "Alice", "CARD123", "pwd123")) {
        qDebug() << "Add user success.";
    } else {
        qDebug() << "Add user failed.";
    }

    // 查询用户
    QSqlQuery result = m.getUserByCardId("CARD123");
    if (result.next()) {
        qDebug() << "User found:" << result.value("name").toString()
        << "Balance:" << result.value("balance").toDouble();
    } else {
        qDebug() << "User not found.";
    }

    // 修改余额
    if (m.updateBalance("CARD123", 100.0)) {
        qDebug() << "Balance updated.";
    } else {
        qDebug() << "Balance update failed.";
    }

    // 再次查询余额
    result = m.getUserByCardId("CARD123");
    if (result.next()) {
        qDebug() << "Updated Balance:" << result.value("balance").toDouble();
    }

    // 删除用户
    if (m.deleteUser("CARD123")) {
        qDebug() << "User deleted.";
    } else {
        qDebug() << "User deletion failed.";
    }

    // 确认删除
    result = m.getUserByCardId("CARD123");
    if (!result.next()) {
        qDebug() << "Confirmed: user no longer exists.";
    }

//zhr end

    w.show();
    return a.exec();
}
