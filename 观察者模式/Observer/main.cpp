// Observer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "StockObserver.h"
#include "NbaObserver.h"
#include "Secretary.h"

int main()
{
	Secretary tongzhizhe;
	StockObserver tongshi1("魏关闸", &tongzhizhe);
	NbaObserver tongshi2("易管查", &tongzhizhe);

	tongzhizhe.Attach(&tongshi1);
	tongzhizhe.Attach(&tongshi2);
	//tongzhizhe.Detach(&tongshi1);

	tongzhizhe.SetState("老板回来了！");

	tongzhizhe.Notify();

	return 0;
}

