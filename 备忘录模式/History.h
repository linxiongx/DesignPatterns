#pragma once

#include "EditorMemento.h"
#include <list>

class History
{
public:
	void push(EditorMemento* pEditorMemento)
	{
		m_lstEditorMemento.push_back(pEditorMemento);
	}

	EditorMemento* pop()
	{
		EditorMemento* ptr = nullptr;
		if (m_lstEditorMemento.size() > 0)
		{
			ptr = m_lstEditorMemento.back();
			m_lstEditorMemento.pop_back();
		}

		return ptr;
	}

private:
	std::list<EditorMemento*> m_lstEditorMemento;
};