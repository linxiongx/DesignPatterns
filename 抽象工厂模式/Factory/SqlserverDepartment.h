#pragma once

#include "IDepartment.h"
#include <iostream>

class SqlserverDepartment : public IDepartment
{
public:
	virtual void InsertDepartment() override
	{
		std::cout << "�� Sqlserver �� Department ���в���һ����¼��" << std::endl;
	}

	virtual void GetDepartment() override
	{
		std::cout << "�� Sqlserver �� Department ���л�ȡһ����¼��" << std::endl;
	}
};