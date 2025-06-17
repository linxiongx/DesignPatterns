// Strategy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CashContext.h"

int main()
{
	CashContext cashContext("打8折");
	std::cout << cashContext.GetResult(100) << std::endl;
}

