#include "offlinemessagemodel.hpp"
#include "db.h"

// 存储用户的离线消息
void OfflineMsgModel::insert(int userid, string msg)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " insert into offlinemessage(userid, message) value(%d, '%s')", userid, msg.c_str());

    if (sp != nullptr)
    {
        sp->update(sql);
    }
}

// 删除用户的离线消息
void OfflineMsgModel::remove(int userid)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " delete from offlinemessage where userid = %d", userid);

    if (sp != nullptr)
    {
        sp->update(sql);
    }
}

// 查询用户的离线消息
vector<string> OfflineMsgModel::query(int userid)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " select message from offlinemessage where userid = %d", userid);

    vector<string> vec;
    if (sp != nullptr)
    {
        MYSQL_RES *res = sp->query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            // 把userid 用户的所有离线消息放入vec中返回
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                vec.push_back(row[0]);
            }
            mysql_free_result(res);
            return vec;
        }
    }

    return vec;
}