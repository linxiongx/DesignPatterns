#pragma once

class DrawingApi
{
public:
	virtual void drawCircle(double x, double y, double radius) = 0;
	virtual void drawRectangle(double x, double y, double width, double height) = 0;
};