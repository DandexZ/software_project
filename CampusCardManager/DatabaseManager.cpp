#include "DatabaseManager.h"

// 构造函数，接收数据库路径作为参数
DatabaseManager::DatabaseManager(const QString& path){
    // 使用 SQLite 驱动创建数据库连接
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    // 尝试打开数据库
    if (!m_db.open()) {
        qDebug() << "Failed to open database:" << m_db.lastError().text();
        return;
    }

    // 初始化数据库表结构
    if (!initialize()) {
        qDebug() << "Failed to initialize database tables!";
    }
}

// 初始化数据库结构，包括 users 和 balance_change 和 administrators 三张表
bool DatabaseManager::initialize() {
    QSqlQuery query;

    // 创建 users 表：保存用户的基本信息
    bool success = query.exec("CREATE TABLE IF NOT EXISTS users ("
                              "student_id TEXT PRIMARY KEY, "  // 学号（主键）
                              "name TEXT NOT NULL, "           // 姓名
                              "card_id TEXT UNIQUE, "          // 卡号（唯一）
                              "password TEXT UNIQUE, "         // 密码（唯一）
                              "balance REAL DEFAULT 0.0)");    // 余额（默认0）

    if (!success) {
        qDebug() << "Create users table error:" << query.lastError();
        return false;
    }

    // 创建 balance_change 表：记录每一次余额变动
    success = query.exec("CREATE TABLE IF NOT EXISTS balance_change ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "  // 自动增长ID
                         "date TEXT NOT NULL, "           // 变动日期
                         "card_id TEXT NOT NULL, "        // 相关卡号
                         "change_type TEXT NOT NULL, "    // 变动类型（增加/减少）
                         "amount REAL NOT NULL, "         // 变动金额
                         "FOREIGN KEY (card_id) REFERENCES users(card_id))");  // 外键关联 users 表

    if (!success) {
        qDebug() << "Create balance_change table error:" << query.lastError();
        return false;
    }

    // 创建 administrators 表：保存管理员信息
    success = query.exec("CREATE TABLE IF NOT EXISTS administrators ("
                         "admin_id TEXT PRIMARY KEY, "    // 管理员号（主键）
                         "name TEXT NOT NULL, "           // 姓名
                         "password TEXT UNIQUE)");          // 密码（唯一）

    if (!success) {
        qDebug() << "Create administrators table error:" << query.lastError();
        return false;
    }

    return true;
}

// 封装的 SQL 执行函数，统一处理 SQL 执行和错误输出
QSqlQuery DatabaseManager::executeQuery(const QString& queryStr) {
    QSqlQuery query(m_db);
    if (!query.exec(queryStr)) {
        qDebug() << "SQL Error:" << query.lastError().text();
    }
    return query;
}

//用户查询
QSqlQuery DatabaseManager::getUserInfoAsUser(const QString& studentId) {
    QString queryStr = QString("SELECT * FROM users WHERE student_id = '%1'").arg(studentId);
    return executeQuery(queryStr);
}

//用户更改自己
bool DatabaseManager::modifyUserSelf(const QString& studentId, const QString& newName, const QString& newPassword) {
    QString queryStr = QString("UPDATE users SET name = '%1', password = '%2' WHERE student_id = '%3'")
    .arg(newName, newPassword, studentId);
    return executeQuery(queryStr).lastError().type() == QSqlError::NoError;
}

//管理员查询
QSqlQuery DatabaseManager::getUserInfoAsAdmin(const QString& studentId) {
    QString queryStr = QString("SELECT * FROM users WHERE student_id = '%1'").arg(studentId);
    return executeQuery(queryStr);
}

//查询管理员
QSqlQuery DatabaseManager::getAdminInfo(const QString& admin_id) {
    QString queryStr = QString("SELECT * FROM administrators WHERE admin_id = '%1'").arg(admin_id);
    return executeQuery(queryStr);
}

//管理员修改用户
bool DatabaseManager::modifyUserAsAdmin(const QString& studentId, const QString& name,
                                        const QString& cardId, const QString& password, double balance) {
    QString queryStr = QString("UPDATE users SET name = '%1', card_id = '%2', password = '%3', balance = %4 "
                               "WHERE student_id = '%5'")
                           .arg(name, cardId, password)
                           .arg(balance)
                           .arg(studentId);
    return executeQuery(queryStr).lastError().type() == QSqlError::NoError;
}

//增加余额变动记录
bool DatabaseManager::insertBalanceChange(const QString& cardId, const QString& changeType, double amount) {
    QString insertLog = QString("INSERT INTO balance_change (date, card_id, change_type, amount) "
                                "VALUES (datetime('now'), '%1', '%2', %3)")
                            .arg(cardId, changeType)
                            .arg(amount);
    return executeQuery(insertLog).lastError().type() == QSqlError::NoError;
}

//查询余额变动记录
QSqlQuery DatabaseManager::queryBalanceChanges(const QString& cardId) {
    QString queryStr = QString("SELECT * FROM balance_change WHERE card_id = '%1' ORDER BY date DESC").arg(cardId);
    return executeQuery(queryStr);
}

// 添加新用户，返回是否成功
bool DatabaseManager::addUser(const QString& studentId, const QString& name, const QString& cardId, const QString& password) {
    QString queryStr = QString(
                           "INSERT INTO users (student_id, name, card_id, password) "
                           "VALUES ('%1', '%2', '%3', '%4')")
                           .arg(studentId, name, cardId, password);

    // 使用 executeQuery 执行并检查是否出错
    return executeQuery(queryStr).lastError().type() == QSqlError::NoError;
}

// 根据 card_id 删除用户，返回是否成功
bool DatabaseManager::deleteUser(const QString& cardId) {
    QString queryStr = QString("DELETE FROM users WHERE card_id = '%1'").arg(cardId);
    return executeQuery(queryStr).lastError().type() == QSqlError::NoError;
}

// 查询用户信息（通过 card_id），返回 QSqlQuery 结果
QSqlQuery DatabaseManager::getUserByCardId(const QString& cardId) {
    QString queryStr = QString("SELECT * FROM users WHERE card_id = '%1'").arg(cardId);
    return executeQuery(queryStr);
}

// 更新用户余额，并记录变动日志，返回是否成功
bool DatabaseManager::updateBalance(const QString& cardId, double amount) {
    QSqlQuery query(m_db);

    // 启动事务，确保余额更新与日志插入同时成功或失败
    QSqlDatabase::database().transaction();

    // 更新余额
    QString updateStr = QString("UPDATE users SET balance = balance + %1 WHERE card_id = '%2'")
                            .arg(amount).arg(cardId);
    if (!query.exec(updateStr)) {
        qDebug() << "Balance update error:" << query.lastError();
        m_db.rollback();
        return false;
    }

    // 准备插入余额变动记录
    QString type = (amount >= 0) ? "increase" : "decrease";
    QString insertLog = QString("INSERT INTO balance_change (date, card_id, change_type, amount) "
                                "VALUES (datetime('now'), '%1', '%2', %3)")
                            .arg(cardId, type).arg(qAbs(amount));
    if (!query.exec(insertLog)) {
        qDebug() << "Balance change log insert error:" << query.lastError();
        m_db.rollback();
        return false;
    }

    // 提交事务
    return m_db.commit();
}
