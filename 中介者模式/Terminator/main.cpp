// Terminator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ChatRoom.h"
#include "AdminUser.h"
#include "NormalUser.h"

int main()
{
    auto pChatRoom = std::make_shared<ChatRoom>();
    
    auto pAdminUser = std::make_shared<AdminUser>("管理员", pChatRoom);
    auto pNormalUserA = std::make_shared<NormalUser>("普通用户A", pChatRoom);
    auto pNormalUserB = std::make_shared<NormalUser>("普通用户B", pChatRoom);

    pChatRoom->addUser(pAdminUser);
    pChatRoom->addUser(pNormalUserA);
    pChatRoom->addUser(pNormalUserB);

    pAdminUser->send("这是管理员信息");
    pNormalUserA->send("这是普通用户A信息");
    pNormalUserB->send("这是普通用户B信息");

    return 0;
}

