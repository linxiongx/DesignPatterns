#pragma once

#include <string>

class CharacterStyle
{
public:
	CharacterStyle(const std::string& family, int size, const std::string& color)
		: m_strFontFamily(family), m_nFontSize(size), m_strColor(color)
	{

	}

	// 用于比较两个样式是否相同
	bool operator==(const CharacterStyle& other) const {
		return m_strFontFamily == other.m_strFontFamily &&
			m_nFontSize == other.m_nFontSize &&
			m_strColor == other.m_strColor;
	}

	std::string fontFamily() const
	{
		return m_strFontFamily;
	}

	int fontSize() const
	{
		return m_nFontSize;
	}

	std::string color() const
	{
		return m_strColor;
	}

protected:
	std::string m_strFontFamily;
	int m_nFontSize;
	std::string m_strColor;
};

namespace std
{
	template<>
	struct hash<CharacterStyle>
	{
		size_t operator()(const CharacterStyle& style) const
		{
			// 组合各个字段的哈希值
			size_t h1 = std::hash<std::string>{}(style.fontFamily());
			size_t h2 = std::hash<int>{}(style.fontSize());
			size_t h3 = std::hash<std::string>{}(style.color());
			return h1 ^ (h2 << 1) ^ (h3 << 2); // 一种简单的组合哈希值的方法
		}
	};
}