#pragma once
#include "Operation.h"
#include "OperationAdd.h"
#include "OperationSub.h"
#include "OperationMul.h"
#include "OperationDiv.h"
#include <memory>
#include <stdexcept>

class OperationFactory
{
public:
	static std::unique_ptr<Operation> createOperation(char operation)
	{
		std::unique_ptr<Operation> ptr = nullptr;
		switch (operation)
		{
		case '+':
			ptr = std::make_unique<OperationAdd>();
			break;
		case '-':
			ptr = std::make_unique<OperationSub>();
			break;
		case '+*':
			ptr = std::make_unique<OperationMul>();
			break;
		case '/':
			ptr = std::make_unique<OperationDiv>();
			break;
		default:
			throw std::runtime_error("Î´ÖªµÄÔËËã·û");
		}
		return ptr;
	}
};