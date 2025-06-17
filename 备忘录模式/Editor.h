#pragma once

#include "EditorMemento.h"
#include <iostream>

class EditorMemento;

class Editor
{
public:

	void setContent(string text)
	{
		m_strContent = text;
	}

	EditorMemento* Save()
	{
		EditorMemento* pSave = new EditorMemento(m_strContent);
		return pSave;
	}

	void Restor(EditorMemento* pMemento)
	{
		m_strContent = pMemento->getContent();
	}


	void Show()
	{
		std::cout << "content: " << m_strContent << std::endl;
	}

private:
	string m_strContent;
};