// Bridge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "DirectXDrawingApi.h"
#include "OpenglDrawingApi.h"

int main()
{

    std::shared_ptr<Shape> ptr = std::make_shared<Circle>(std::make_shared<OpenglDrawingApi>());
    ptr->Draw();

    return 0;
}

