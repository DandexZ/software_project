#include "DatabaseManager.h"

//连接sqlite数据库
bool DatabaseManager::initialize(const QString& path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Database error:" << m_db.lastError();
        return false;
    }

    // 建表（首次运行时执行）
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "username TEXT UNIQUE,"
               "password TEXT,"
               "role INTEGER)"); // 0-用户 1-管理员
    // 其他表（cards, transactions...）
    return true;
}

