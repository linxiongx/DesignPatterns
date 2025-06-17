#pragma once

#include "User.h"
#include <iostream>

class NormalUser : public User
{
public:
	NormalUser(string strName, std::shared_ptr<ChatMediator> ptrChatMediator)
		: User(strName, ptrChatMediator)
	{

	}

	virtual void send(const string& strMessage)
	{
		auto ptr = m_pChatMediator.lock();
		if (ptr != nullptr)
		{
			ptr->sendMessage(strMessage, getName());
		}
	}

	virtual void receive(const string& strMessage)
	{
		std::cout << getName() << "收到信息：" << strMessage << std::endl;
	}

};