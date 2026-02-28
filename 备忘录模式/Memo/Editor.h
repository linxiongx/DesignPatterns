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

	std::shared_ptr<EditorMemento> Save()
	{
		//std::shared_ptr 的构造函数内部会尝试创建 EditorMemento 对象
		//	但 EditorMemento 的构造函数是私有的
		//	std::shared_ptr 不是 EditorMemento 的友元，无法访问私有构造函数
		//  std::shared_ptr<EditorMemento> spEditor = std::make_shared<EditorMemento>(m_strContent);

		std::shared_ptr<EditorMemento> spEditor{ new EditorMemento(m_strContent) };
		return spEditor;
	}

	void Restor(std::shared_ptr<EditorMemento> pMemento)
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