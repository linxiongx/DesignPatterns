#pragma once

#include "CashSuper.h"
#include "CashNormal.h"
#include "CashRebate.h"
#include "CashReturn.h"
#include <string>
#include <stdexcept>
#include <memory>

using std::string;

class CashContext
{
public:
	CashContext(string type)
	{
		if (type == "�����շ�")
		{
			m_pCashSuper = std::make_unique<CashNormal>();
		}
		else if (type == "��300��100")
		{
			m_pCashSuper = std::make_unique<CashReturn>(300, 100);
		}
		else if (type == "��8��")
		{
			m_pCashSuper = std::make_unique<CashRebate>(0.8);
		} 
		else
		{
			throw std::runtime_error("δ֪�շ�����");
		}
	}

	double GetResult(double money)
	{
		return m_pCashSuper->acceptCash(money);
	}

private:
	std::unique_ptr<CashSuper> m_pCashSuper = nullptr;
};