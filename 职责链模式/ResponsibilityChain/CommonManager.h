#pragma once

#include "Manager.h"

class CommonManager : public Manager
{
public:
	virtual void handler(double dMoney)
	{
		if (dMoney < 1000000)
		{
			std::cout << "����˵��С��100��С��˼��׼�ˣ�" << std::endl;
		}
		else
		{
			std::cout << "���� -> ";
			m_ptrSuperior->handler(dMoney);
		}
	}
};