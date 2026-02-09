#pragma once
#include "Command.h"
#include "Light.h"
#include "TV.h"
#include "Stereo.h"
#include <memory> 

using namespace std;

// 具体命令 (Concrete Command) - 开灯
// 改回使用 Raw Pointer：命令不拥有接收者，只是引用它。
class LightOnCommand : public Command
{
private:
    Light* light;

public:
    LightOnCommand(Light* light) : light(light) {}

    void execute() override
    {
        light->on();
    }
};

// 具体命令 (Concrete Command) - 关灯
class LightOffCommand : public Command
{
private:
    Light* light;

public:
    LightOffCommand(Light* light) : light(light) {}

    void execute() override
    {
        light->off();
    }
};

// 具体命令 - 打开电视
class TVOnCommand : public Command
{
private:
    TV* tv;

public:
    TVOnCommand(TV* tv) : tv(tv) {}

    void execute() override
    {
        tv->turnOn();
    }
};

// 具体命令 - 关闭电视
class TVOffCommand : public Command
{
private:
    TV* tv;

public:
    TVOffCommand(TV* tv) : tv(tv) {}

    void execute() override
    {
        tv->turnOff();
    }
};

// 具体命令 - 打开音响并设置音量
class StereoOnWithCDCommand : public Command
{
private:
    Stereo* stereo;
    int volume; // 保存参数

public:
    StereoOnWithCDCommand(Stereo* stereo, int volume) : stereo(stereo), volume(volume) {}

    void execute() override
    {
        stereo->on();
        stereo->setCD();
        stereo->setVolume(volume); // 使用保存的参数
    }
};

class StereoOffCommand : public Command
{
private:
    Stereo* stereo;

public:
    StereoOffCommand(Stereo* stereo) : stereo(stereo) {}

    void execute() override
    {
        stereo->off();
    }
};
