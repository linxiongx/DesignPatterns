#pragma once

class Character
{
public:
	virtual ~Character() = default;
	virtual void display(char symbol, int x, int y) const = 0;
};