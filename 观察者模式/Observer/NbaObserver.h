#pragma once

#include "Observer.h"


class NbaObserver : public Observer
{
public:
	NbaObserver(string name, Subject* sub)
		:Observer(sub), m_strName(name)
	{

	}

	void Update()
	{
		cout << m_pSubject->GetState() << " " << m_strName << "�ر�NBA������������" << std::endl;
	}

private:
	string m_strName;
};