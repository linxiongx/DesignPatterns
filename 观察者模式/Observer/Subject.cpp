#include "Subject.h"
#include "Observer.h"

void Subject::Attach(Observer* observer)
{
	m_lstObservers.push_back(observer);
}

void Subject::Detach(Observer* observer)
{
	for (auto iter = m_lstObservers.begin(); iter != m_lstObservers.end(); ++iter)
	{
		if (observer == *iter)
		{
			m_lstObservers.erase(iter);
			break;
		}
	}
}

void Subject::Notify()
{
	for (auto iter = m_lstObservers.begin(); iter != m_lstObservers.end(); ++iter)
	{
		(*iter)->Update();
	}
}
