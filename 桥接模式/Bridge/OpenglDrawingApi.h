#pragma once

#include "DrawingApi.h"
#include <iostream>

class OpenglDrawingApi : public DrawingApi
{
public:
	virtual void drawCircle(double x, double y, double radius)
	{
		std::cout << "OpenglDrawingApi::drawCircle()" << std::endl;
	}

	virtual void drawRectangle(double x, double y, double width, double height)
	{
		std::cout << "OpenglDrawingApi::drawRectangle()" << std::endl;
	}
};