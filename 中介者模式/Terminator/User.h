#pragma once

#include "ChatMediator.h"

class User
{
public:
	User(string strName, std::weak_ptr<ChatMediator> ptrChatMediator)
		: m_strName(strName), m_pChatMediator(ptrChatMediator)
	{
		
	}

	virtual ~User() = default;

	virtual void send(const string& strMessage) = 0;
	
	virtual void receive(const string& strMessage) = 0;
	
	inline virtual string getName() 
	{
		return m_strName;
	}

protected:
	string m_strName;
	std::weak_ptr<ChatMediator> m_pChatMediator;
};