#pragma once

#include "EventListener.h"
#include "Event.h"
#include <iostream>

class LoggerListener : public EventListener
{
public:
	LoggerListener(const string& name)
		: m_strName(name)
	{

	}

	void onEvent(const Event& event) override
	{
		std::cout << "[" << m_strName << " Logger]" << event.getData() << std::endl;
	}

private:
	string m_strName;
};