#pragma once

#include "IDepartment.h"
#include <iostream>

class MysqlDepartment : public IDepartment
{
public:
	virtual void InsertDepartment() override
	{
		std::cout << "�� Mysql �� Department ���в���һ����¼��" << std::endl;
	}

	virtual void GetDepartment() override
	{
		std::cout << "�� Mysql �� Department ���л�ȡһ����¼��" << std::endl;
	}
};