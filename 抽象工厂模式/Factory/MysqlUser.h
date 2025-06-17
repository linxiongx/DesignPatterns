#pragma once

#include "IUser.h"
#include <iostream>

class MysqlUser : public IUser
{
public:
	virtual void InsertUser() override
	{
		std::cout << "�� Mysql �� User ���в���һ����¼��" << std::endl;
	}

	virtual void GetUser() override
	{
		std::cout << "�� Mysql �� User ���л�ȡһ����¼��" << std::endl;
	}
};