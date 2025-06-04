#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QVariant>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QStandardPaths>
class DatabaseManager {
public:
    static DatabaseManager& instance(const QString& path = "");
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
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

    QString getCardIdByStudentId(const QString& studentId);
    QString getStudentIdByCardId(const QString& cardId);
    QString getNameByStudentId(const QString& studentId);
    QString getNameByCardId(const QString& cardId);
    QString getBalanceByStudentId(const QString& studentId);
  QString getBalanceByCardId(const QString& cardId);
    QString getAdminNameById(const QString& adminId);
    QString getLastBalanceChangeType(const QString& cardId);
    QString getLastBalanceChangeAmount(const QString& cardId);
    QString getLastBalanceChangeTime(const QString& cardId);
    QString getTotalUserCount();
    QString getTotalBalance();
    QString getusr_password(const QString &studentId);
    QString getadmin_password(const QString &adminId);

private:
    DatabaseManager(const QString& path); // 私有构造函数
    QSqlDatabase m_db;
    QString m_dbPath;
};

#endif // DATABASEMANAGER_H
