#pragma once

#include "DrawingApi.h"
#include <iostream>

class DirectXDrawingApi : public DrawingApi
{
public:
	virtual void drawCircle(double x, double y, double radius)
	{
		std::cout << "DirectXDrawingApi::drawCircle()" << std::endl;
	}

	virtual void drawRectangle(double x, double y, double width, double height)
	{
		std::cout << "DirectXDrawingApi::drawRectangle()" << std::endl;
	}
};