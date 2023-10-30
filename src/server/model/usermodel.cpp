#include "usermodel.hpp"
#include "db.h"
#include <iostream>
using namespace std;

// User 表的增加方法
bool UserModel::insert(User &user)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " insert into user(name, password, state) value('%s', '%s', '%s')", user.getName().c_str(), user.getPwd().c_str(), user.getState().c_str());

    if (sp != nullptr)
    {
        // if (mysql.update(sql))
        if (sp->update(sql))
        {
            // 获取插入成功用户数据生成的主键id
            user.setId(mysql_insert_id(sp->getConnection()));
            return true;
        }
    }

    return false;
}

// 跟据用户号码查询用户信息
User UserModel::query(int id)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " select * from user where id = %d", id);

    if (sp != nullptr)
    {
        MYSQL_RES *res = sp->query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr)
            {
                User user;
                user.setId(atoi(row[0])); // 可以通过[]取值
                user.setName(row[1]);
                user.setPwd(row[2]);
                user.setState(row[3]);
                mysql_free_result(res);
                return user;
            }
        }
    }

    return User();
}

// 更新用户的状态信息
bool UserModel::updateState(User user)
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " update user set state = '%s' where id = %d", user.getState().c_str(), user.getId());

    if (sp != nullptr)
    {
        return sp->update(sql);
    }

    return false;
}

// 重置用户的状态信息
void UserModel::resetState()
{
    shared_ptr<MySQL> sp = pool->getConnection();
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, " update user set state = 'offline' where state = 'online'");

    if (sp != nullptr)
    {
        sp->update(sql);
    }
}