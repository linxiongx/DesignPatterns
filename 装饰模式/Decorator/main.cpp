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

	do {
		std::unique_ptr<Coffee> coffee = std::make_unique<SimpleCoffee>();

		std::cout << "=== ���ȶ���ϵͳ ===\n";
		std::cout << "����: " << coffee->getDescription() << " - " << coffee->getCost() << "\n\n";

		char choice;

		std::cout << "�Ƿ����ţ��? (y/n): ";
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			coffee = std::make_unique<MilkDecorator>(std::move(coffee));
			std::cout << "��Ӻ�: " << coffee->getDescription() << " - " << coffee->getCost() << "\n";
		}

		std::cout << "�Ƿ������? (y/n): ";
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			coffee = std::make_unique<SugarDecorator>(std::move(coffee));
			std::cout << "��Ӻ�: " << coffee->getDescription() << " - " << coffee->getCost() << "\n";
		}

		std::cout << "�Ƿ��������? (y/n): ";
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			coffee = std::make_unique<WhipDecorator>(std::move(coffee));
			std::cout << "��Ӻ�: " << coffee->getDescription() << " - " << coffee->getCost() << "\n";
		}
	} while (0);

	return 0;
}