#pragma once

#include "IUser.h"
#include <iostream>

class SqlserverUser : public IUser
{
public:
	virtual void InsertUser() override
	{
		std::cout << "�� Sqlserver �� User ���в���һ����¼��" << std::endl;
	}

	virtual void GetUser() override
	{
		std::cout << "�� Sqlserver �� User ���л�ȡһ����¼��" << std::endl;
	}
};