#pragma once

#include <string>
using std::string;

class Event
{
public:
	Event(const string& data)
		:m_strData(data)
	{ 
	}

	string getData() const
	{
		return m_strData;
	}

private:
	string m_strData;
};