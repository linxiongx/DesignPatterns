// Factory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DataAccess.h"

int main()
{
    //std::unique_ptr<IDepartment> pDepartment = std::make_unique<IDepartment>(DataAccess::CreateDepartment()); //error
    std::unique_ptr<IDepartment> pDepartment(DataAccess::CreateDepartment());
    pDepartment->InsertDepartment();

    std::unique_ptr<IUser> pUser(DataAccess::CreateUser());
    pUser->InsertUser();

    return 0;
}

