#pragma once

#include <memory>
#include "CashSuper.h"
#include "CashNormal.h"
#include "CashRebate.h"
#include "CashReturn.h"
#include <string>
#include <stdexcept>
using std::string;

class CashFactory
{
public:
	static std::unique_ptr<CashSuper> createCashAccept(string type)
	{
		std::unique_ptr<CashSuper> ptr = nullptr;
		if (type == "�����շ�")
		{
			ptr = std::make_unique<CashNormal>();
		}
		else if (type == "��300��100")
		{
			ptr = std::make_unique<CashRebate>(300, 100);
		}
		else if (type == "��8��")
		{
			ptr = std::make_unique<CashReturn>(0.8);
		}
		else
		{
			throw std::runtime_error("δ֪�շ�����");
		}
		return ptr;
	}
};
