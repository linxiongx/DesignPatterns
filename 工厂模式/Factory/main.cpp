// Factory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "OperationFactory.h"

int main()
{
	std::unique_ptr<Operation> ptr = OperationFactory::createOperation('+');
	std::cout << ptr->GetResult(2, 3) << std::endl;
}

