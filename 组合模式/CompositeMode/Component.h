#pragma once

#include <string>
using std::string;
#include <iostream>

class Component
{
public:
	Component(string id)
		: m_strID(id)
	{

	}

	virtual ~Component() 
	{

	}

	string getID() const
	{
		return m_strID;
	}

	virtual void operation() const
	{
		std::cout << "执行组件[" << m_strID << "]操作" << std::endl;
	}

	virtual void add(std::shared_ptr<Component> p)
	{

	}

	virtual void remove(std::shared_ptr<Component> p)
	{

	}

	virtual std::shared_ptr<Component> find(string strID)
	{
		return {};
	}

protected:
	string m_strID;
};