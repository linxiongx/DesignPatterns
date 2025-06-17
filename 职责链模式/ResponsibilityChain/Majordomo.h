#pragma once

#include "Manager.h"

class Majordomo : public Manager
{
public:
	virtual void handler(double dMoney)
	{
		if (dMoney < 10000000)
		{
			std::cout << "总监说：小于1000万，小意思，准了！" << std::endl;
		}
		else
		{
			std::cout << "总监 -> ";
			m_ptrSuperior->handler(dMoney);
		}
	}
};