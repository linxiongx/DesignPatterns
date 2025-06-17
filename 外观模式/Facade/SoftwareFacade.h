#pragma once

#include <iostream>
using namespace std;
#include <string>
using std::string;

class Os
{
public:
	void loadKernel()
	{
		cout << "����ϵͳ�����ں�" << endl;
	}
};

class Application
{
public:
	void start()
	{
		cout << "Ӧ�ó�������" << endl;
	}
};

class Database
{
public:
	void connect()
	{
		cout << "���ݿ�����" << endl;
	}
};

class SoftwareFacade
{
public:
	void start()
	{
		cout << "�������..." << endl;
		_os.loadKernel();
		_database.connect();
		_application.start();
		cout << "����������" << endl;
	}

private:
	Os _os;
	Application _application;
	Database _database;
};