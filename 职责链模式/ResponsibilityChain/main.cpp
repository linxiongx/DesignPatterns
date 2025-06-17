// ResponsibilityChain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GeneraManager.h"
#include "Majordomo.h"
#include "CommonManager.h"

int main()
{
    auto pCommonManager = std::make_shared<CommonManager>();
    auto pMajordomo = std::make_shared<Majordomo>();
    auto pGeneralManger = std::make_shared<GeneraManager>();

    pCommonManager->setSuperior(pMajordomo);
    pMajordomo->setSuperior(pGeneralManger);

    std::cout << "开始申请经费：" << std::endl;

    pCommonManager->handler(10);
    pCommonManager->handler(1000001);
    pCommonManager->handler(10000001);
    pCommonManager->handler(100000001);

    std::cout << "Hello World!\n";
}
