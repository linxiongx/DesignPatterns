#pragma once

#include "Component.h"

class Leaf : public Component
{
public:
	Leaf(string id)
		: Component(id)
	{

	}
	virtual std::shared_ptr<Component> find(string strID)
	{
		if (strID == m_strID)
			return std::shared_ptr<Component>(this, [](Component*) {});

		return nullptr;
	}

	virtual void operation() const
	{
		std::cout << "ִ�����[" << m_strID << "]����" << std::endl;
	}
};