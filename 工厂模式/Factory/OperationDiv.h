#pragma once

#include "Operation.h"
#include <stdexcept>

class OperationDiv : public Operation
{
public:
	virtual double GetResult(double numberA, double numberB) override
	{
		if (numberB == 0)
			throw std::runtime_error("��������Ϊ0");
		return numberA / numberB;
	}
};