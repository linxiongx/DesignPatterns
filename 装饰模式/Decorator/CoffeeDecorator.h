#pragma once

#include "Coffee.h"
#include <memory>

class CoffeeDecorator : public Coffee
{
public:
	CoffeeDecorator(std::unique_ptr<Coffee> pCoffee)
	: m_pDecoratorCoffee(std::move(pCoffee))
	{

	}

	virtual ~CoffeeDecorator() = default;

public:
	virtual double getCost() const override
	{
		return m_pDecoratorCoffee->getCost();
	}

	virtual string getDescription() const override
	{
		return m_pDecoratorCoffee->getDescription();
	}

protected:
	std::unique_ptr<Coffee> m_pDecoratorCoffee;
};