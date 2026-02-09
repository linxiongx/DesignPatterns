#pragma once
#include "Command.h"
#include "LambdaCommand.h"
#include <memory>
#include <queue>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>

using namespace std;

// 调用者 (Invoker)
// 异步版本：后台线程顺序处理命令
class RemoteControl
{
private:
    queue<shared_ptr<Command>> commandQueue; // 任务队列
    mutex queueMutex;                        // 互斥锁保护队列
    condition_variable cv;                   // 条件变量用于通知
    thread workerThread;                     // 后台工作线程
    atomic<bool> stopWorker;                 // 停止标志

    // 工作线程函数 (消费者)
    void processCommands()
    {
        while (true)
        {
            shared_ptr<Command> cmd;
            {
                unique_lock<mutex> lock(queueMutex);
                // 等待直到有命令或者收到停止信号
                cv.wait(lock, [this] { return !commandQueue.empty() || stopWorker; });

                if (stopWorker && commandQueue.empty())
                {
                    return; // 退出线程
                }

                if (!commandQueue.empty())
                {
                    cmd = commandQueue.front();
                    commandQueue.pop();
                }
            }

            // 在锁外执行命令，避免阻塞生产
            if (cmd)
            {
                cout << "[Worker Thread " << this_thread::get_id() << "] Processing command..." << endl;
                // 模拟耗时操作，更能看出异步效果
                this_thread::sleep_for(chrono::milliseconds(500)); 
                cmd->execute();
            }
        }
    }

public:
    RemoteControl() : stopWorker(false)
    {
        // 启动后台线程
        workerThread = thread(&RemoteControl::processCommands, this);
    }

    ~RemoteControl()
    {
        // 优雅退出
        {
            lock_guard<mutex> lock(queueMutex);
            stopWorker = true;
        }
        cv.notify_one(); // 唤醒线程去检查 stopWorker
        if (workerThread.joinable())
        {
            workerThread.join(); // 等待线程结束
        }
    }

    // 添加命令 (生产者)
    void addCommand(shared_ptr<Command> cmd)
    {
        if (cmd)
        {
            {
                lock_guard<mutex> lock(queueMutex);
                commandQueue.push(cmd);
                cout << "[Invoker Main] Added command to queue." << endl;
            }
            cv.notify_one(); // 通知后台线程干活
        }
    }

    // Lambda 版本的便捷方法
    // 允许直接传递可调用对象（lambda、函数指针等）
    void addCommand(std::function<void()> func)
    {
        addCommand(make_shared<LambdaCommand>(func));
    }
};
