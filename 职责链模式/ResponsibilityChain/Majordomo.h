#pragma once

#include "Manager.h"

class Majordomo : public Manager
{
public:
	virtual void handler(double dMoney)
	{
		if (dMoney < 10000000)
		{
			std::cout << "�ܼ�˵��С��1000��С��˼��׼�ˣ�" << std::endl;
		}
		else
		{
			std::cout << "�ܼ� -> ";
			m_ptrSuperior->handler(dMoney);
		}
	}
};