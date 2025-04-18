#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(const QString& path){
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Failed to open database:" << m_db.lastError().text();
        return;
    }

    // 初始化表结构
    if (!initialize()) {
        qDebug() << "Failed to initialize database tables!";
    }
}

//连接sqlite数据库
bool DatabaseManager::initialize() {

    // 创建users表
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS users ("
                              "student_id TEXT PRIMARY KEY, "  // 学号作为主键
                              "name TEXT NOT NULL, "          // 姓名
                              "card_id TEXT UNIQUE, "         // 卡号，唯一
                              "password TEXT UNIQUE, "         // 密码，唯一
                              "balance REAL DEFAULT 0.0)");   // 余额，默认为0

    if (!success) {
        qDebug() << "Create users table error:" << query.lastError();
        return false;
    }

    // 创建cards表（余额变动记录表）
    success = query.exec("CREATE TABLE IF NOT EXISTS cards ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "date TEXT NOT NULL, "           // 日期
                         "card_id TEXT NOT NULL, "        // 卡号
                         "change_type TEXT NOT NULL, "    // 增加/减少
                         "amount REAL NOT NULL, "         // 变动金额
                         "FOREIGN KEY (card_id) REFERENCES users(card_id))");  // 外键关联

    if (!success) {
        qDebug() << "Create cards table error:" << query.lastError();
        return false;
    }

    return true;
}

