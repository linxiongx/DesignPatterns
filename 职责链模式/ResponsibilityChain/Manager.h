#pragma once

#include <memory>
#include <iostream>

class Manager
{
public:
	void setSuperior(std::shared_ptr<Manager> ptr)
	{
		m_ptrSuperior = ptr;
	}

	virtual void handler(double) = 0;

protected:
	std::shared_ptr<Manager> m_ptrSuperior = nullptr;
};