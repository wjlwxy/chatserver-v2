#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include <vector>
#include "user.hpp"
#include "ConnectionPool.h"
using namespace std;

// 维护好友信息表的操作接口方法
class FriendModel
{
public:
    // 添加好友关系
    void insert(int userid, int friendid);

    // 返回用户好友列表  friendid friendname
    vector<User> query(int userid);

private:
    ConnectionPool *pool = ConnectionPool::getConnectionPool();
};

#endif
