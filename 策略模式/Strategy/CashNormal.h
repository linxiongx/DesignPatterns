#pragma once

#include "CashSuper.h"


class CashNormal : public CashSuper
{
public:
	virtual double acceptCash(double money) override
	{
		return money;
	}
};