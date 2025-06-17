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
		cout << m_pSubject->GetState() << " " << m_strName << "�رչ�Ʊ���飬����������" << std::endl;
	}

private:
	string m_strName;
};