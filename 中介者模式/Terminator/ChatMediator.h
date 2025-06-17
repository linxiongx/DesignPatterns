#pragma once

#include <memory>
#include <string>
using std::string;

class User;
class ChatMediator
{
public:
	virtual ~ChatMediator() = default;
	virtual void sendMessage(string strMessage, string strName) = 0;
	virtual void addUser(std::shared_ptr<User> ptrUser) = 0;
};