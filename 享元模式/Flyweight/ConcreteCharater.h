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
		std::cout << "��ʾ�ַ���" << symbol << " ��λ�ã�(" << x << "," << y << ")"
			<< " ʹ�����壺" << m_characterStyle.fontFamily()
			<< " ��С��" << m_characterStyle.fontSize()
			<< " ��ɫ��" << m_characterStyle.color() << std::endl;
	}

private:
	CharacterStyle m_characterStyle;
};