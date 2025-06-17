#pragma once

#include "State.h"
#include "NoonState.h"

class ForenoonState : public State
{
public:
	virtual void WriteProgram(Work* w) override
	{
		if (w->Hour() < 12)
		{
			cout << "当前时间: " << w->Hour() << " 点，上午工作，精神百倍" << std::endl;
		}
		else
		{
			w->setState(std::make_unique<NoonState>());
			w->WriteProgram();
		}
	}

};