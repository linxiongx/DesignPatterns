#pragma once

#include "CashSuper.h"
#include <math.h>

class CashReturn : public CashSuper
{
public:
	CashReturn(double condition, double moneyReturn)
		: m_moneyCondition(condition), m_moneyReturn(moneyReturn)
	{

	}

	virtual double acceptCash(double money) override
	{
		double result = money;
		if (money >= m_moneyCondition)
			result = money - floor(money / m_moneyCondition) * m_moneyReturn;
		
		return result;
	}

private:
	double m_moneyCondition = 0.0f;
	double m_moneyReturn = 0.0f;
};