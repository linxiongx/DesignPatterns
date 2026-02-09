#pragma once
#include <memory> // Added for smart pointers

// 命令接口 (Command Interface)
// 声明执行操作的接口
class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};
