#pragma once

#include "CharacterFactory.h"

class TextEditor
{
public:
	void displayCharacter(char symbol, int x, int y, const std::string& fontFamily, int fontSize, const std::string& color)
	{
		CharacterStyle style(fontFamily, fontSize, color);
		
		std::shared_ptr<Character> character = m_characterFactory.getCharacter(style);

		character->display(symbol, x, y);
	}

	void showStats()
	{
		std::cout << "当前使用的不同样式的数量：" << m_characterFactory.getTotalStyle() << std::endl;
	}

private:
	CharacterFactory m_characterFactory;
};
 