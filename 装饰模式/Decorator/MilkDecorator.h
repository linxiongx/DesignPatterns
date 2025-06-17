#pragma once

#include "CoffeeDecorator.h"

class MilkDecorator : public CoffeeDecorator
{
public:
	MilkDecorator(std::unique_ptr<Coffee> pCoffee)
		: CoffeeDecorator(std::move(pCoffee))
	{

	}

	virtual double getCost() const override
	{
		return m_pDecoratorCoffee->getCost() + 2.0;
	}

	virtual string getDescription() const override
	{
		return m_pDecoratorCoffee->getDescription() + ", with milk";
	}
};