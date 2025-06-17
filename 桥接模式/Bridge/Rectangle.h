#pragma once

#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(std::shared_ptr<DrawingApi> pDrawingApi)
		: Shape(pDrawingApi)
	{

	}

	virtual void Draw()
	{
		_ASSERT(m_pDrawingApi != nullptr);
		m_pDrawingApi->drawRectangle(1, 1, 1, 1);
	}
};