#pragma once

#include "Character.h"
#include "CharacterStyle.h"
#include <iostream>

class ConcreteCharacter : public Character
{
public:
	ConcreteCharacter(const CharacterStyle& characterStyle)
		: m_characterStyle(characterStyle)
	{

	}

	virtual void display(char symbol, int x, int y) const
	{
		std::cout << "显示字符：" << symbol << " 在位置：(" << x << "," << y << ")"
			<< " 使用字体：" << m_characterStyle.fontFamily()
			<< " 大小：" << m_characterStyle.fontSize()
			<< " 颜色：" << m_characterStyle.color() << std::endl;
	}

private:
	CharacterStyle m_characterStyle;
};