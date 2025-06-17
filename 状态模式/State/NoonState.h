#pragma once
#include "State.h"
#include "AfternoonState.h"

class NoonState : public State
{
public:
	virtual void WriteProgram(Work* w) override
	{
		if (w->Hour() < 13)
		{
			cout << "当前时间: " << w->Hour() << " 点，饿了，午饭；犯困，午休。" << std::endl;
		}
		else
		{
			w->setState(std::make_unique<AfternoonState>());
			w->WriteProgram();
		}
	}
};