#pragma once

#include <string>
using std::string;

class Editor;
class EditorMemento
{
	friend class Editor;
private:
	EditorMemento(string strContent) // 将构造函数设为私有，只允许友元类访问
		: m_strContent(strContent)
	{

	}

	string getContent()
	{
		return m_strContent;
	}

private:
	string m_strContent;

public:
	// 不提供公共访问接口，保护内部状态
};