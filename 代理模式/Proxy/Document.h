#pragma once

class Document
{
public:
	virtual ~Document() = default;

	virtual void read() const = 0;
	virtual void write() const = 0;
};