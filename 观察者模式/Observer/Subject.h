#pragma once

#include <string>
#include <list>

class Observer;

class Subject
{
public:
	virtual void Attach(Observer* observer);

	virtual void Detach(Observer* observer);

	virtual void Notify();

	virtual void SetState(std::string action) = 0;

	virtual std::string GetState() = 0;

protected:
	std::list<Observer*> m_lstObservers;
};