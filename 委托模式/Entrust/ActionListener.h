#pragma once

#include "EventListener.h"
#include <iostream>

class ActionListener : public EventListener
{
public:
	void onEvent(const Event& event) override
	{
		std::cout << "Executing action in response to: " << event.getData() << std::endl;
	}
};