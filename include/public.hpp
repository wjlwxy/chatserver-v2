#ifndef PUBLIC_H
#define PUBLIC_H
#include <iostream>
using namespace std;

/*
server 和 client的公共文件
*/

enum EnMsgType
{
    LOGIN_MSG = 1,  // 登录消息
    LOGIN_MSG_ACK,  // 登录响应消息
    LOGINOUT_MSG,   // 注销消息
    REG_MSG,        // 注册消息
    REG_MSG_ACK,    // 注册响应消息
    ONE_CHAT_MSG,   // 聊天消息
    ADD_FRIEND_MSG, // 添加好友消息

    CREATE_GROUP_MSG, // 创建群组
    CREATE_GROUP_ACK, // 创建群组响应
    ADD_GROUP_MSG,    // 加入群组
    GROUP_CHAT_MSG,   // 群聊天
};

#define LOG(str) \
    cout << __FILE__ << " : " << __LINE__ << " " << __TIMESTAMP__ << " : " << str << endl;

#endif