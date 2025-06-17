#pragma once

#include "Observer.h"


class StockObserver : public Observer
{
public:
	StockObserver(string name, Subject* sub)
		:Observer(sub), m_strName(name)
	{

	}

	void Update()
	{
		cout << m_pSubject->GetState() << " " << m_strName << "关闭股票行情，继续工作！" << std::endl;
	}

private:
	string m_strName;
};