#pragma once
#include "Command.h"
#include <functional>

// Lambda 命令 (Lambda Command)
// 使用 std::function 封装可调用对象（lambda、函数指针、仿函数等）
// 解决命令模式中的类爆炸问题
class LambdaCommand : public Command
{
private:
    std::function<void()> action;

public:
    // 接受任何可调用对象
    LambdaCommand(std::function<void()> func) : action(func) {}

    void execute() override
    {
        if (action)
        {
            action();
        }
    }
};
