#pragma once

#include <iostream>
using namespace std;
#include <string>
using std::string;

class Cpu
{
public:
	void execute()
	{
		cout << "CPU 执行指令" << endl;
	}
};

class Memory
{
public:
	void allocate()
	{
		cout << "内存分配空间" << endl;
	}
};

class HardDrive
{
public:
	void readData()
	{
		cout << "硬盘读取数据" << endl;
	}
};

class HardwareFacade
{
public:
	void initialize()
	{
		cout << "初始化硬件..." << endl;
		_memory.allocate();
		_hardDrive.readData();
		_cpu.execute();
	}

private:
	Cpu _cpu;
	Memory _memory;
	HardDrive _hardDrive;
};