#pragma once

#include <string>
using std::string;

class Operation
{
public:
	virtual ~Operation() = default;
	virtual double GetResult(double numberA, double numberB) = 0;
};