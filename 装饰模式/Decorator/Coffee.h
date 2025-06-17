#pragma once

#include <string>
using std::string;

class Coffee
{
public:
	virtual ~Coffee() = default;

	virtual double getCost() const = 0;
	virtual string getDescription() const = 0;
};