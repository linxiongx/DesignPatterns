#pragma once

#include "CashSuper.h"

class CashRebate : public CashSuper
{
public:
	CashRebate(double bate)
		: m_moneyRebate(bate)
	{

	}

	virtual double acceptCash(double money) override
	{
		return money * m_moneyRebate;
	}

private:
	double m_moneyRebate = 1.0;
};