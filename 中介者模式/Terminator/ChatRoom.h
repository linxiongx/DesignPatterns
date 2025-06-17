#pragma once

#include "ChatMediator.h"
#include <unordered_map>
#include <iostream>

class ChatRoom : public ChatMediator
{
public:
	virtual void sendMessage(string strMessage, string strName);

	virtual void addUser(std::shared_ptr<User> ptrUser);

protected:
	std::unordered_map<string, std::shared_ptr<User>> m_mapUsers;
};