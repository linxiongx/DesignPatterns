#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(std::shared_ptr<DrawingApi> pDrawingApi)
		: Shape(pDrawingApi)
	{

	}

	virtual void Draw()
	{
		_ASSERT(m_pDrawingApi != nullptr);
		m_pDrawingApi->drawCircle(1, 1, 1);
	}
};