#pragma once
#include <string>
using std::string;
#include <iostream>
using std::cout;

#include "Subject.h"

class Observer
{
public:
	Observer(Subject* sub)
		:m_pSubject(sub)
	{

	}

	virtual void Update() = 0;

protected:
	Subject* m_pSubject;
};