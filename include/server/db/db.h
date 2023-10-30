#ifndef DB_H
#define DB_H

#include <mysql/mysql.h>
#include <string>
using namespace std;

// 数据库操作类
class MySQL
{
public:
    // 初始化数据库连接
    MySQL();
    // 释放数据库连接资源
    ~MySQL();
    // 连接数据库
    bool connect(string server, unsigned short port, string user, string password,
                 string dbname);
    // 更新操作
    bool update(string sql);
    // 查询操作
    MYSQL_RES *query(string sql);
    // 获取连接
    MYSQL *getConnection();

    // 用于清除长时间未使用的连接
    void refreshAliveTime() { _alivetime = clock(); }

    clock_t getAliveTime() const { return clock() - _alivetime; }

private:
    MYSQL *_conn;
    clock_t _alivetime;
};

#endif