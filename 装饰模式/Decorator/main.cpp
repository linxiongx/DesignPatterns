#include <iostream>
using namespace std;

#include "SimpleCoffee.h"
#include "CoffeeDecorator.h"
#include "WhipDecorator.h"
#include "SugarDecorator.h"
#include "MilkDecorator.h"

int main()
{
	auto coffee = std::make_unique<SimpleCoffee>();
	cout << "Cost: " << coffee->getCost() << ";  Description: " << coffee->getDescription() << endl;

	auto milkCoffee = std::make_unique<MilkDecorator>(std::move(coffee));
	cout << "Cost: " << milkCoffee->getCost() << ";  Description: " << milkCoffee->getDescription() << endl;

	auto sweetMikCoffeee = std::make_unique<SugarDecorator>(std::move(milkCoffee));
	cout << "Cost: " << sweetMikCoffeee->getCost() << ";  Description: " << sweetMikCoffeee->getDescription() << endl;

	auto whipDecorator = std::make_unique<WhipDecorator>(std::move(sweetMikCoffeee));
	cout << "Cost: " << whipDecorator->getCost() << ";  Description: " << whipDecorator->getDescription() << endl;



	return 0;
}