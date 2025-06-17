#pragma once

#include "IDepartment.h"
#include <iostream>

class SqlserverDepartment : public IDepartment
{
public:
	virtual void InsertDepartment() override
	{
		std::cout << "在 Sqlserver 的 Department 表中插入一条记录。" << std::endl;
	}

	virtual void GetDepartment() override
	{
		std::cout << "从 Sqlserver 的 Department 表中获取一条记录。" << std::endl;
	}
};