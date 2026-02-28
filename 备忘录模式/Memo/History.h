#pragma once

#include "EditorMemento.h"
#include <list>

class History
{
public:
	void push(std::shared_ptr<EditorMemento> spEditorMemento)
	{
		m_lstEditorMemento.push_back(spEditorMemento);
	}

	std::shared_ptr<EditorMemento> pop()
	{
		std::shared_ptr<EditorMemento> sp = nullptr;
		if (m_lstEditorMemento.size() > 0)
		{
			sp = m_lstEditorMemento.back();
			m_lstEditorMemento.pop_back();
		}

		return sp;
	}

private:
	std::list<std::shared_ptr<EditorMemento>> m_lstEditorMemento;
};