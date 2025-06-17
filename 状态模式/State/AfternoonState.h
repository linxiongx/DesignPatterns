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
			cout << "��ǰʱ��: " << w->Hour() << " �㣬����״̬����������Ŭ����" << std::endl;
		}
		else
		{
			w->setState(std::make_unique<RestState>());
			w->WriteProgram();
		}
	}
};