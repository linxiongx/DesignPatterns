#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "Light.h"
#include "TV.h"
#include "Stereo.h"
#include "ConcreteCommand.h"
#include "Invoker.h"

using namespace std;

int main()
{
    // 1. 创建接收者 (Receiver) - Client 拥有并管理生命周期
    shared_ptr<Light> livingRoomLight = make_shared<Light>();

    // 2. 创建具体命令 (Concrete Command) - 传递 Raw Pointer
    // 命令对象引用接收者，但“不拥有”接收者
    shared_ptr<Command> lightOn = make_shared<LightOnCommand>(livingRoomLight.get());
    shared_ptr<Command> lightOff = make_shared<LightOffCommand>(livingRoomLight.get());

    // 3. 创建调用者 (Invoker)
    unique_ptr<RemoteControl> remote = make_unique<RemoteControl>();

    // 4. 执行命令 -  addCommand 会自动执行，无需手动 pressButton
    cout << "Adding LightOn Command:" << endl;
    remote->addCommand(lightOn);

    cout << "\nAdding LightOff Command:" << endl;
    remote->addCommand(lightOff);

    cout << "------------------------" << endl;

    // 6. 创建电视及其命令
    shared_ptr<TV> livingRoomTV = make_shared<TV>();
    shared_ptr<Command> tvOn = make_shared<TVOnCommand>(livingRoomTV.get());
    shared_ptr<Command> tvOff = make_shared<TVOffCommand>(livingRoomTV.get());

    // 7. 复用同一个调用者 (RemoteControl) 来控制电视
    cout << "\n[Using same Remote] Adding TVOn Command:" << endl;
    remote->addCommand(tvOn);

    cout << "\n[Using same Remote] Adding TVOff Command:" << endl;
    remote->addCommand(tvOff);

    cout << "------------------------" << endl;

    // 9. 创建音响及其命令（带参数）
    shared_ptr<Stereo> stereo = make_shared<Stereo>();
    // 这里的 11 就是我们传递的参数，它会被保存在命令对象中
    shared_ptr<Command> stereoOn = make_shared<StereoOnWithCDCommand>(stereo.get(), 11);
    shared_ptr<Command> stereoOff = make_shared<StereoOffCommand>(stereo.get());

    // 10. 执行带参数的命令
    cout << "\n[Using same Remote] Adding StereoOn Command:" << endl;
    remote->addCommand(stereoOn);

    cout << "\n[Using same Remote] Adding StereoOff Command:" << endl;
    remote->addCommand(stereoOff);

    cout << "\n------------------------" << endl;
    cout << "[Main] All commands submitted. Waiting for background thread..." << endl;
    
    // 给后台线程一点时间处理队列中的任务
    // 实际项目中通常会有更好的同步机制，或在 Invoker 析构时等待
    this_thread::sleep_for(chrono::seconds(5));

    cout << "\n========================" << endl;
    cout << "[Main] 使用 Lambda 表达式创建命令 (避免类爆炸)" << endl;
    cout << "========================" << endl;

    // 使用 Lambda 表达式创建命令 - 无需定义新的命令类
    // 场景1：简单控制灯光
    cout << "\n[Lambda] Adding Light control commands:" << endl;
    remote->addCommand([&livingRoomLight]() {
        cout << "[Lambda Command] Executing: Light On" << endl;
        livingRoomLight->on();
    });

    remote->addCommand([&livingRoomLight]() {
        cout << "[Lambda Command] Executing: Light Off" << endl;
        livingRoomLight->off();
    });

    // 场景2：控制电视
    cout << "\n[Lambda] Adding TV control commands:" << endl;
    remote->addCommand([&livingRoomTV]() {
        cout << "[Lambda Command] Executing: TV On" << endl;
        livingRoomTV->turnOn();
    });

    // 场景3：复杂操作 - 音响设置（捕获多个参数）
    cout << "\n[Lambda] Adding Stereo complex commands:" << endl;
    int customVolume = 15;
    remote->addCommand([&stereo, customVolume]() {
        cout << "[Lambda Command] Executing: Stereo setup with volume " << customVolume << endl;
        stereo->on();
        stereo->setCD();
        stereo->setVolume(customVolume);
    });

    // 场景4：组合命令 - 一次执行多个操作
    cout << "\n[Lambda] Adding composite command:" << endl;
    remote->addCommand([&livingRoomLight, &livingRoomTV, &stereo]() {
        cout << "[Lambda Command] Executing: Turn everything off (composite action)" << endl;
        livingRoomLight->off();
        livingRoomTV->turnOff();
        stereo->off();
    });

    cout << "\n[Main] Lambda commands submitted. Waiting for execution..." << endl;
    this_thread::sleep_for(chrono::seconds(6));

    // 不需要手动 delete，智能指针会自动管理内存！
    // 顺序：scopes 结束 -> Command 释放 -> Receiver 释放(由 main 中的 shared_ptr 管理)
    cout << "\n[System] Resources will be cleaned up automatically." << endl;

    return 0;
}