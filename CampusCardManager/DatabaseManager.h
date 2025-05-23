#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
// DatabaseManager.h
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
class DatabaseManager {
public:
    static DatabaseManager& instance();
    DatabaseManager(const QString& path);
    bool initialize(); // 初始化数据库连接
    QSqlQuery executeQuery(const QString& query); // 执行SQL
    // 其他便捷方法（如用户是否存在、充值等）
private:
    QSqlDatabase m_db;
    DatabaseManager() {} // 单例模式
};

#endif // DATABASEMANAGER_H
