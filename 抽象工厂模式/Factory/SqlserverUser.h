#pragma once

#include "IUser.h"
#include <iostream>

class SqlserverUser : public IUser
{
public:
	virtual void InsertUser() override
	{
		std::cout << "在 Sqlserver 的 User 表中插入一条记录。" << std::endl;
	}

	virtual void GetUser() override
	{
		std::cout << "从 Sqlserver 的 User 表中获取一条记录。" << std::endl;
	}
};