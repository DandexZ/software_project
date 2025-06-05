#include "DatabaseManager.h"

DatabaseManager& DatabaseManager::instance(const QString& path) {
    static DatabaseManager instance(path);
    return instance;
}

DatabaseManager::DatabaseManager(const QString& path)
    : m_dbPath(path) {
    // 初始化数据库表结构
    if (!initialize()) {
        qDebug() << "Failed to initialize database tables!";
    }
}

// 初始化数据库结构，包括 users 和 balance_change 和 administrators 三张表
bool DatabaseManager::initialize() {
    // 使用 SQLite 驱动创建数据库连接
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_dbPath);

    // 尝试打开数据库
    if (!m_db.open()) {
        qDebug() << "Failed to open database:" << m_db.lastError().text();
        return false;
    }
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

bool DatabaseManager::find_usrid(const QString& studentId) {
    QString queryStr = QString("SELECT * FROM users WHERE student_id = '%1'").arg(studentId);
    return executeQuery(queryStr).lastError().type() == QSqlError::NoError;

}

//用户更改自己
bool DatabaseManager::modifyUserSelf(const QString& studentId, const QString& newName, const QString& newPassword) {
    QString queryStr = QString("UPDATE users SET name = '%1', password = '%2' WHERE student_id = '%3'")
    .arg(newName, newPassword, studentId);
    return executeQuery(queryStr).lastError().type() == QSqlError::NoError;
}

//修改管理员自己密码
bool DatabaseManager::modifyadminSelf(const QString& adminId, const QString& newPassword) {
    QString queryStr = QString("UPDATE administrators SET  password = '%1' WHERE admin_id = '%2'")
    .arg( newPassword, adminId);
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

// 根据学号获取卡号
QString DatabaseManager::getCardIdByStudentId(const QString& studentId) {
    QString queryStr = QString("SELECT card_id FROM users WHERE student_id = '%1'").arg(studentId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("card_id").toString();
    }
    return "";
}

// 根据卡号获取学号
QString DatabaseManager::getStudentIdByCardId(const QString& cardId) {
    QString queryStr = QString("SELECT student_id FROM users WHERE card_id = '%1'").arg(cardId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("student_id").toString();
    }
    return "";
}

// 根据学号获取姓名
QString DatabaseManager::getNameByStudentId(const QString& studentId) {
    QString queryStr = QString("SELECT name FROM users WHERE student_id = '%1'").arg(studentId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("name").toString();
    }
    return "";
}


// 根据卡号获取姓名
QString DatabaseManager::getNameByCardId(const QString& cardId) {
    QString queryStr = QString("SELECT name FROM users WHERE card_id = '%1'").arg(cardId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("name").toString();
    }
    return "";
}

// 根据学号获取余额（字符串形式）
QString DatabaseManager::getBalanceByStudentId(const QString& studentId) {
    QString queryStr = QString("SELECT balance FROM users WHERE student_id = '%1'").arg(studentId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return QString::number(query.value("balance").toDouble(), 'f', 2);
    }
    return "0.00";
}

//根据学号获取密码
QString DatabaseManager::getpasswordByStudentId(const QString& studentId) {
    QString queryStr = QString("SELECT password FROM users WHERE student_id = '%1'").arg(studentId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("password").toString();
    }
    return "";
}

// 根据卡号获取余额（字符串形式）
QString DatabaseManager::getBalanceByCardId(const QString& cardId) {
    QString queryStr = QString("SELECT balance FROM users WHERE card_id = '%1'").arg(cardId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return QString::number(query.value("balance").toDouble(), 'f', 2);
    }
    return "0.00";
}
//注册信息错误
QString DatabaseManager::register_error(const QString& studentId, const QString& name, const QString& cardId, const QString& password)
 {
    if(DatabaseManager::instance().find_usrid(studentId)){
        return "学号重复";
    }
     if(DatabaseManager::instance().getCardIdByStudentId(studentId)==cardId){
    return "卡号重复";}

<<<<<<< HEAD
QString DatabaseManager::register_error(const QString& studentId, const QString& name_id, const QString& cardId, const QString& password)
 {
     if(getCardIdByStudentId(studentId)==cardId){
    return "卡号重复";}

     if(getNameByStudentId(studentId)==name_id){
    return "学号重复";
  }
     if(getpasswordByStudentId(studentId)==password){
    return "密码重复";
  }
}

=======
     if(DatabaseManager::instance().getNameByStudentId( studentId)==name){
    return "姓名重复";
  }

     if(DatabaseManager::instance().getpasswordByStudentId(studentId)==password){
    return "密码重复";
  }
     else return "";
}
>>>>>>> c538fc938fe34d59b67600b13afda9afb8c8b166
// 根据管理员ID获取姓名
QString DatabaseManager::getAdminNameById(const QString& adminId) {
    QString queryStr = QString("SELECT name FROM administrators WHERE admin_id = '%1'").arg(adminId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("name").toString();
    }
    return "";
}

// 获取最近一次余额变动类型
QString DatabaseManager::getLastBalanceChangeType(const QString& cardId) {
    QString queryStr = QString("SELECT change_type FROM balance_change "
                              "WHERE card_id = '%1' ORDER BY date DESC LIMIT 1").arg(cardId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("change_type").toString();
    }
    return "无记录";
}

// 获取最近一次余额变动金额
QString DatabaseManager::getLastBalanceChangeAmount(const QString& cardId) {
    QString queryStr = QString("SELECT amount FROM balance_change "
                              "WHERE card_id = '%1' ORDER BY date DESC LIMIT 1").arg(cardId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return QString::number(query.value("amount").toDouble(), 'f', 2);
    }
    return "0.00";
}

// 获取最近一次余额变动时间
QString DatabaseManager::getLastBalanceChangeTime(const QString& cardId) {
    QString queryStr = QString("SELECT date FROM balance_change "
                              "WHERE card_id = '%1' ORDER BY date DESC LIMIT 1").arg(cardId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("date").toString();
    }
    return "无记录";
}

// 获取用户总数
QString DatabaseManager::getTotalUserCount() {
    QSqlQuery query = executeQuery("SELECT COUNT(*) FROM users");
    if (query.next()) {
        return query.value(0).toString();
    }
    return "0";
}

// 获取总余额
QString DatabaseManager::getTotalBalance() {
    QSqlQuery query = executeQuery("SELECT SUM(balance) FROM users");
    if (query.next()) {
        return QString::number(query.value(0).toDouble(), 'f', 2);
    }
    return "0.00";
}

//获取用户密码
QString DatabaseManager::getusr_password(const QString &studentId) {
    QString queryStr = QString("SELECT password FROM users WHERE student_id = '%1'").arg(studentId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("password").toString();
    }
    return "";
}
//获取管理员密码
QString DatabaseManager::getadmin_password(const QString &adminId) {
    QString queryStr = QString("SELECT password FROM administrators WHERE admin_id = '%1'").arg(adminId);
    QSqlQuery query = executeQuery(queryStr);

    if (query.next()) {
        return query.value("password").toString();
    }
    return "";
}

