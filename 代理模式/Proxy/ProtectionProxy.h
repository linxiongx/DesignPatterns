#pragma once

#include "Document.h"
#include "ReadDocument.h"
#include <memory>

class ProtectionProxy : public Document
{
public:
	ProtectionProxy(const string& name, const string& content, const string& role)
		: m_ptrDocument(std::make_unique<ReadDocument>(name, content)), m_strRole(role)
	{

	}

	virtual void read() const override
	{
		m_ptrDocument->read();
	}

	virtual void write() const override
	{
		if (m_strRole == "admin")
		{
			m_ptrDocument->write();
		}
		else
		{
			std::cout << "Error: You don't have permission to modify this document!";
		}
	}

private:
	std::unique_ptr<ReadDocument> m_ptrDocument;
	std::string m_strRole;
};