#include "ChatRoom.h"

#include "User.h"

void ChatRoom::addUser(std::shared_ptr<User> ptrUser)
{
	if (ptrUser)
	{
		if (m_mapUsers.find(ptrUser->getName()) == m_mapUsers.end())
		{
			std::cout << ptrUser->getName() << "¼ÓÈëÈºÁÄ" << std::endl;
			m_mapUsers[ptrUser->getName()] = ptrUser;
		}
	}
}

void ChatRoom::sendMessage(string strMessage, string strName)
{
	//if (auto iter = m_mapUsers.find(strName); iter != m_mapUsers.end())
	//{
	//	iter->second->receive(strMessage);
	//}
	for (auto iter = m_mapUsers.begin(); iter != m_mapUsers.end(); ++iter)
	{
		if (iter->second->getName() != strName)
		{
			iter->second->receive(strMessage);
		}
	}
}