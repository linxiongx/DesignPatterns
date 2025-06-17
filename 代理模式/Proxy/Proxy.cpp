// Proxy.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ProtectionProxy.h"

int main()
{
	auto adminDoc = std::make_unique<ProtectionProxy>("confidential.txt", "Top Secret Context", "admin");
	auto userDoc = std::make_unique<ProtectionProxy>("confidential.txt", "Top Secret Context", "user");

	adminDoc->read();
	adminDoc->write();

	userDoc->read();
	userDoc->write();

	return 0;
}

