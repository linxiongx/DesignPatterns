#pragma once

#include "CoffeeDecorator.h"

class SugarDecorator : public CoffeeDecorator
{
public:
	SugarDecorator(std::unique_ptr<Coffee> pCoffee)
		: CoffeeDecorator(std::move(pCoffee))
	{

	}
	virtual double getCost() const override
	{
		return m_pDecoratorCoffee->getCost() + 1.0;
	}

	virtual string getDescription() const override
	{
		return m_pDecoratorCoffee->getDescription() + ", with sugar";
	}
};