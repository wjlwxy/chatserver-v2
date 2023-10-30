#include "friendmodel.hpp"
#include "db.h"

// 添加好友关系
void FriendModel::insert(int userid, int friendid)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " insert into friend value(%d, %d)", userid, friendid);

    if (sp != nullptr)
    {
        sp->update(sql);
    }
}

// 返回用户好友列表  friendid friendname
vector<User> FriendModel::query(int userid)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " select a.id,a.name,a.state from user a inner join friend b on b.friendid = a.id where b.userid = %d", userid);

    vector<User> vec;
    if (sp != nullptr)
    {
        MYSQL_RES *res = sp->query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            // 把userid 用户的所有离线消息放入vec中返回
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                vec.push_back(user);
            }
            mysql_free_result(res);
            return vec;
        }
    }

    return vec;
}