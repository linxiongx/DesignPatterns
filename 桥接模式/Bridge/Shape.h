#pragma once

#include "DrawingApi.h"
#include <memory>

class Shape
{
public:
	Shape(std::shared_ptr<DrawingApi> pDrawingApi)
		: m_pDrawingApi(pDrawingApi)
	{

	}

	virtual ~Shape() = default;

	virtual void Draw() = 0;

protected:
	std::shared_ptr<DrawingApi> m_pDrawingApi = nullptr;
};