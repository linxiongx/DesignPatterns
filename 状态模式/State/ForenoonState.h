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
			cout << "��ǰʱ��: " << w->Hour() << " �㣬���繤��������ٱ�" << std::endl;
		}
		else
		{
			w->setState(std::make_unique<NoonState>());
			w->WriteProgram();
		}
	}

};