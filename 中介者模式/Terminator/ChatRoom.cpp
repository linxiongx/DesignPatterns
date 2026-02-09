#include "ChatRoom.h"

#include "User.h"

void ChatRoom::addUser(std::weak_ptr<User> ptrUser)
{
	std::shared_ptr<User> p = ptrUser.lock();
	if (p)
	{
		if (m_mapUsers.find(p->getName()) == m_mapUsers.end())
		{
			std::cout << p->getName() << "¼ÓÈëÈºÁÄ" << std::endl;
			m_mapUsers[p->getName()] = ptrUser;
		}
	}
}

void ChatRoom::sendMessage(string strMessage, string strName)
{
	for (auto iter = m_mapUsers.begin(); iter != m_mapUsers.end(); ++iter)
	{
		std::shared_ptr<User> p = iter->second.lock();
		if (p != nullptr)
		{
			if (p->getName() != strName)
			{
				p->receive(strMessage);
			}
		}

	}
}