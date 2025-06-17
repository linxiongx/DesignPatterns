#pragma once

#include <vector>
#include "EventListener.h"

class EventSource
{
public:
	void addListener(EventListener* pListener)
	{
		for (auto iter = m_lstEventListener.begin(); iter != m_lstEventListener.end(); ++iter)
		{
			if (*iter == pListener)
				return;
		}
		m_lstEventListener.push_back(pListener);
	}

	void removeListener(EventListener* pListener)
	{
		for (auto iter = m_lstEventListener.begin(); iter != m_lstEventListener.end(); ++iter)
		{
			if (*iter == pListener)
			{
				m_lstEventListener.erase(iter);
				return;
			}
		}
	}

protected:
	void notify(const Event& event)
	{
		for (auto iter = m_lstEventListener.begin(); iter != m_lstEventListener.end(); ++iter)
		{
			(*iter)->onEvent(event);
		}
	}

private:
	std::vector<EventListener*> m_lstEventListener;
};