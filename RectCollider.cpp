#include "RectCollider.h"

RectCollider::RectCollider()
	:
	top(-1),
	bottom(-1),
	left(-1),
	right(-1),
	centerx(-1),
	centery(-1),
	width(-1),
	height(-1)
{
}

RectCollider::~RectCollider()
{
}

void RectCollider::SetRectCenter(float _cx, float _cy, float _width, float _height)
{
	centerx = _cx;
	centery = _cy;
	width = _width;
	height = _height;
	top = centery + height / 2.0;
	bottom = centery - height / 2.0;
	left = centerx - width / 2.0;
	right = centerx + width / 2.0;

}

void RectCollider::SetRectTopBottom(float _left, float _top, float _width, float _height)
{
	left = _left;
	top = _top;
	width = _width;
	height = _height;
	centery = top - height / 2.0;
	bottom = top - height;
	centerx = left + width / 2.0;
	right = left + width;
}

float RectCollider::GetLeft()
{
	return left;
}

float RectCollider::GetRight()
{
	return right;
}

float RectCollider::GetTop()
{
	return top;
}

float RectCollider::GetBottom()
{
	return bottom;
}

float RectCollider::GetCenterX()
{
	return centerx;
}

float RectCollider::GetCenterY()
{
	return centery;
}

float RectCollider::GetWidth()
{
	return width;
}

float RectCollider::GetHeight()
{
	return height;
}
