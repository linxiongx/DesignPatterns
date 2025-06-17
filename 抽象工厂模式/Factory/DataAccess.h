#pragma once

#include "MysqlUser.h"
#include "SqlserverUser.h"
#include "MysqlDepartment.h"
#include "SqlserverDepartment.h"

class DataAccess
{
public:
	static IUser* CreateUser()
	{
		IUser* pIUser = nullptr;
		switch (m_database)
		{
		case 'm':
			pIUser = new MysqlUser;
			break;
		case 's':
			pIUser = new SqlserverUser;
			break;
		default:
			throw std::runtime_error("未知的数据库类型!");
			break;
		}
		return pIUser;
	}

	static IDepartment* CreateDepartment()
	{
		IDepartment* pIDepartment = nullptr;
		switch (m_database)
		{
		case 'm':
			pIDepartment = new MysqlDepartment;
			break;
		case 's':
			pIDepartment = new SqlserverDepartment;
			break;
		default:
			throw std::runtime_error("未知的数据库类型!");
			break;
		}
		return pIDepartment;
	}

private:
	static const char m_database = 'm';
};