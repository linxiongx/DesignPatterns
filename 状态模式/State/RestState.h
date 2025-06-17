#pragma once

#include "State.h"

class RestState : public State
{
public:
	virtual void WriteProgram(Work* w) override
	{
		cout << "当前时间: " << w->Hour() << " 点，下班回家了！" << std::endl;
	}
};