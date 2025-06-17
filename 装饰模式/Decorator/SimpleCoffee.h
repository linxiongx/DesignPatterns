#pragma once

#include "Coffee.h"

class SimpleCoffee : public Coffee
{
public:
	double getCost() const override
	{
		return 10.0;
	}

	string getDescription() const override
	{
		return "Simple coffee";
	}
};