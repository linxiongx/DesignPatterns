#pragma once

#include "State.h"
#include "RestState.h"

class AfternoonState : public State
{
public:
	virtual void WriteProgram(Work* w) override
	{
		if (w->Hour() < 17)
		{
			cout << "当前时间: " << w->Hour() << " 点，下午状态还不错，继续努力！" << std::endl;
		}
		else
		{
			w->setState(std::make_unique<RestState>());
			w->WriteProgram();
		}
	}
};