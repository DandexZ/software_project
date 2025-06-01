#include "mainwindow.h"
#include "DatabaseManager.h"
#include <QApplication>

QString getDatabasePath() {
/* 获取应用数据存储路径
    会从database_initial中复制初始数据库到该Debug/Release/ProFile，数据不互通，仅在该处修改
*/
    QString dataDir = QCoreApplication::applicationDirPath();
    QDir dir(dataDir);
    if (!dir.exists()) dir.mkpath(".");  // 确保目录存在

    QString dbPath = dataDir + "/data.db";
    // 如果数据库不存在，从资源文件复制初始数据库
    if (!QFile::exists(dbPath)) {
        QFile::copy(":/database_initial/data.db", dbPath);
        QFile::setPermissions(dbPath, QFile::WriteOwner | QFile::ReadOwner);
    }
    return dbPath;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString dbPath = getDatabasePath();
    qDebug() << "数据库路径为 "<< dbPath;
    DatabaseManager::instance(dbPath);

//zhr测试数据库语句
    /*
    使用说明：
        使用单例模式保证数据库干净
        在项目任何地方使用 DatabaseManager::instance() 即可使用数据库
*/
    // 添加用户
    if (DatabaseManager::instance().addUser("20230101", "Alice", "CARD123", "pwd123")) {
        qDebug() << "Add user success.";
    } else {
        qDebug() << "Add user failed.";
    }

    // 查询用户
    QSqlQuery result = DatabaseManager::instance().getUserByCardId("CARD123");
    if (result.next()) {
        qDebug() << "User found:" << result.value("name").toString()
        << "Balance:" << result.value("balance").toDouble();
    } else {
        qDebug() << "User not found.";
    }

    // 修改余额
    if (DatabaseManager::instance().updateBalance("CARD123", 100.0)) {
        qDebug() << "Balance updated.";
    } else {
        qDebug() << "Balance update failed.";
    }

    // 再次查询余额
    result = DatabaseManager::instance().getUserByCardId("CARD123");
    if (result.next()) {
        qDebug() << "Updated Balance:" << result.value("balance").toDouble();
    }

    // 删除用户
    if (DatabaseManager::instance().deleteUser("CARD123")) {
        qDebug() << "User deleted.";
    } else {
        qDebug() << "User deletion failed.";
    }

    // 确认删除
    result = DatabaseManager::instance().getUserByCardId("CARD123");
    if (!result.next()) {
        qDebug() << "Confirmed: user no longer exists.";
    }
//zhr end

    w.show();
    return a.exec();
}
