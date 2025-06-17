#pragma once

#include <string>
using std::string;

class Editor;
class EditorMemento
{
	friend class Editor;
private:
	EditorMemento(string strContent)
		: m_strContent(strContent)
	{

	}

	string getContent()
	{
		return m_strContent;
	}

private:
	string m_strContent;
};