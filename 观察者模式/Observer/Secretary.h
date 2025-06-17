#pragma once

#include "Subject.h"

class Secretary : public Subject
{
public:

	void SetState(std::string state)
	{
		m_strState = state;
	}

	std::string GetState()
	{
		return m_strState;
	}

private:

	std::string m_strState;
};