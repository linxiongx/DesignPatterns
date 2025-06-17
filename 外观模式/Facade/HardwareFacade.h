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
		cout << "CPU ִ��ָ��" << endl;
	}
};

class Memory
{
public:
	void allocate()
	{
		cout << "�ڴ����ռ�" << endl;
	}
};

class HardDrive
{
public:
	void readData()
	{
		cout << "Ӳ�̶�ȡ����" << endl;
	}
};

class HardwareFacade
{
public:
	void initialize()
	{
		cout << "��ʼ��Ӳ��..." << endl;
		_memory.allocate();
		_hardDrive.readData();
		_cpu.execute();
	}

private:
	Cpu _cpu;
	Memory _memory;
	HardDrive _hardDrive;
};