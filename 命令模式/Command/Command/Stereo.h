#pragma once
#include <iostream>
using namespace std;

// 接收者 (Stereo) - 音响
// 演示带有参数的操作 (setVolume)
class Stereo
{
public:
    void on()
    {
        cout << "Stereo is ON" << endl;
    }

    void off()
    {
        cout << "Stereo is OFF" << endl;
    }

    void setCD()
    {
        cout << "Stereo is set for CD input" << endl;
    }

    void setVolume(int volume)
    {
        cout << "Stereo volume set to " << volume << endl;
    }
};
