#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QVariant>
#include <QDebug>
class DatabaseManager {
public:
    static DatabaseManager& instance();
    DatabaseManager(const QString& path);
    bool initialize(); // 初始化数据库连接
    QSqlQuery executeQuery(const QString& query); // 执行SQL

    // 增删查改接口
    bool addUser(const QString& studentId, const QString& name, const QString& cardId, const QString& password);
    bool deleteUser(const QString& cardId);
    QSqlQuery getUserByCardId(const QString& cardId);
    bool updateBalance(const QString& cardId, double amount);

    //完善查改
    QSqlQuery getUserInfoAsUser(const QString& studentId);
    bool modifyUserSelf(const QString& studentId, const QString& newName, const QString& newPassword);
    QSqlQuery getUserInfoAsAdmin(const QString& studentId);
    bool modifyUserAsAdmin(const QString& studentId, const QString& name, const QString& cardId, const QString& password, double balance);
    bool insertBalanceChange(const QString& cardId, const QString& changeType, double amount);
    QSqlQuery queryBalanceChanges(const QString& cardId);
    QSqlQuery getAdminInfo(const QString& admin_id);


private:
    QSqlDatabase m_db;
    DatabaseManager() {} // 单例模式
};

#endif // DATABASEMANAGER_H
