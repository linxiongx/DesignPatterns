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
		cout << "操作系统加载内核" << endl;
	}
};

class Application
{
public:
	void start()
	{
		cout << "应用程序启动" << endl;
	}
};

class Database
{
public:
	void connect()
	{
		cout << "数据库链接" << endl;
	}
};

class SoftwareFacade
{
public:
	void start()
	{
		cout << "软件启动..." << endl;
		_os.loadKernel();
		_database.connect();
		_application.start();
		cout << "软件启动完成" << endl;
	}

private:
	Os _os;
	Application _application;
	Database _database;
};