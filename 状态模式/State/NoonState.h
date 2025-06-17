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
			cout << "��ǰʱ��: " << w->Hour() << " �㣬���ˣ��緹�����������ݡ�" << std::endl;
		}
		else
		{
			w->setState(std::make_unique<AfternoonState>());
			w->WriteProgram();
		}
	}
};