#pragma once

#include "Work.h"

class State
{
public:
	virtual void WriteProgram(Work* w) = 0;
};