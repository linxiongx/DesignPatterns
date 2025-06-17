#pragma once

#include "Operation.h"

class OperationMul : public Operation
{
public:
	virtual double GetResult(double numberA, double numberB) override
	{
		return numberA * numberB;
	}
};