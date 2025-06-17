#pragma once

#include "Document.h"
#include <iostream>
#include <string>
using std::string;

class ReadDocument : public Document
{
public:
	ReadDocument(const string& name, const string& content)
		: m_strName(name), m_strContent(content)
	{

	}

	virtual void read() const override
	{
		std::cout << "Reading document: " << m_strName << " - Content: " << m_strContent << std::endl;
	}

	virtual void write() const override
	{
		std::cout << "Writing document: " << m_strName << std::endl;
	}

private:
	string m_strContent;
	string m_strName;
};