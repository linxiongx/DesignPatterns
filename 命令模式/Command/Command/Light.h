#pragma once
#include <iostream>
using namespace std;

// 接收者 (Receiver)
// 负责执行与请求相关的操作
class Light
{
public:
    void on()
    {
        cout << "Light is ON" << endl;
    }

    void off()
    {
        cout << "Light is OFF" << endl;
    }
};
