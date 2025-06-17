#pragma once

#include "Manager.h"

class CommonManager : public Manager
{
public:
	virtual void handler(double dMoney)
	{
		if (dMoney < 1000000)
		{
			std::cout << "经理说：小于100万，小意思，准了！" << std::endl;
		}
		else
		{
			std::cout << "经理 -> ";
			m_ptrSuperior->handler(dMoney);
		}
	}
};