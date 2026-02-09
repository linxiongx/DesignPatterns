#pragma once
#include <iostream>
using namespace std;

// 另一个接收者 (Another Receiver) - 电视
// 注意：它的接口方法名称 (turnOn, turnOff) 与 Light (on, off) 不同
// 但命令模式可以将它们适配为统一的 execute() 调用
class TV
{
public:
    void turnOn()
    {
        cout << "TV is turned ON" << endl;
    }

    void turnOff()
    {
        cout << "TV is turned OFF" << endl;
    }
};
