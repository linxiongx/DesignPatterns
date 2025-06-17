#pragma once

#include <iostream>
using std::cout;

class State;
class Work
{
public:
	Work();
	double Hour()
	{
		return m_dHour;
	}
	
	void setHour(double hour)
	{
		m_dHour = hour;
	}

	void setState(std::unique_ptr<State> pState);

	void WriteProgram();

private:
	double m_dHour;
	std::unique_ptr<State> m_pState;
};