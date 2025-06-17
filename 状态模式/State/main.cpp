// State.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "State.h"

int main()
{
	Work* pWork = new Work();
	pWork->setHour(9);
	pWork->WriteProgram();
	pWork->setHour(12);
	pWork->WriteProgram();
	pWork->setHour(17);
	pWork->WriteProgram();
}

