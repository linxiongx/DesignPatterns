#pragma once

#include "State.h"

class RestState : public State
{
public:
	virtual void WriteProgram(Work* w) override
	{
		cout << "��ǰʱ��: " << w->Hour() << " �㣬�°�ؼ��ˣ�" << std::endl;
	}
};