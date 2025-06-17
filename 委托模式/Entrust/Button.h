#pragma once

#include "EventSource.h"
#include <iostream>

class Button : public EventSource
{
public:
	Button(const string& name)
		: m_strName(name)
	{

	}

	void click()
	{
		std::cout << "send " << m_strName << " click notify" << std::endl;
		Event event("Button " + m_strName + " was clicked!");
		notify(event);
	}

private:
	string m_strName;
};