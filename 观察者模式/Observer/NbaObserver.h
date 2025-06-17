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
		cout << m_pSubject->GetState() << " " << m_strName << "关闭NBA，继续工作！" << std::endl;
	}

private:
	string m_strName;
};