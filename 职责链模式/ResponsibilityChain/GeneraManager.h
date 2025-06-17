#pragma once

#include "Manager.h"

class GeneraManager : public Manager
{
public:
	virtual void handler(double dMoney)
	{
		std::cout << "总经理说：老子有的是钱，这点小事也来问我，准了！" << std::endl;
	}
};