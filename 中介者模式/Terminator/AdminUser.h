#pragma once

#include "User.h"
#include <iostream>

class AdminUser : public User
{
public:
	AdminUser(string strName, std::shared_ptr<ChatMediator> ptrChatMediator)
		: User(strName, ptrChatMediator)
	{

	}

	virtual void send(const string& strMessage)
	{
		std::shared_ptr<ChatMediator> ptr = m_pChatMediator.lock();
		if (ptr != nullptr)
		{
			ptr->sendMessage(strMessage, getName());
		}
	}

	virtual void receive(const string& strMessage)
	{
		std::cout << getName() << "收到信息：" << strMessage << std::endl;
	}

	void announce(const string& strAnnounce)
	{
		auto ptr = m_pChatMediator.lock();
		if (ptr != nullptr)
		{
			ptr->sendMessage("[系统通知] " + strAnnounce, getName());
		}
	}
};