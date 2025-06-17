#pragma once

#include "CharacterStyle.h"
#include "Character.h"
#include "ConcreteCharater.h"
#include <unordered_map>
#include <memory>
#include <iostream>

class CharacterFactory
{
public:
	//CharacterFactory()
	std::shared_ptr<Character> getCharacter(const CharacterStyle& style)
	{
		auto iter = m_mapCharacters.find(style);
		if (iter != m_mapCharacters.end())
		{
			std::cout << "重用已存在的字符样式" << std::endl;
			return iter->second;
		}

		std::cout << "创建新样式: " << style.fontFamily() << "," << style.fontSize() << "," << style.color() << std::endl;
		auto character = std::make_shared<ConcreteCharacter>(style);
		m_mapCharacters[style] = character;
		return character;
	}

	size_t getTotalStyle() const
	{
		return m_mapCharacters.size();
	}

private:
	std::unordered_map<CharacterStyle, std::shared_ptr<Character>> m_mapCharacters;
};