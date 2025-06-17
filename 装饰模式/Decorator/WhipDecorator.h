#pragma once

#include "CoffeeDecorator.h"

class WhipDecorator : public CoffeeDecorator
{
public:
	WhipDecorator(std::unique_ptr<Coffee> pCoffee)
		:CoffeeDecorator(std::move(pCoffee))
	{

	}
	
	virtual double getCost() const override
	{
		return m_pDecoratorCoffee->getCost() + 3.0;
	}

	virtual string getDescription() const override
	{
		return m_pDecoratorCoffee->getDescription() + ", with whip";
	}
};