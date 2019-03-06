#include "button.h"

Button::Button(int x, int y) : baseGlObj(x, y, 0, 0)
{
	this->x = x;
	this->y = y;
}

Button::Button(int x, int y, int w, int h) : baseGlObj(x, y, w, h)
{
	Button(x, y);
	this->w = w;
	this->h = h;
}

Button::Button(int x, int y, int w, int h, void(*drawFunc)(int, int, int, int)) : baseGlObj(x, y, w, h)
{
	Button(x, y, w, h);
	this->drawFunc = drawFunc;
}

Button::Button(int x, int y, void(*drawFunc)(int, int, int, int)) : baseGlObj(x, y, 0, 0)
{
	Button(x, y);
	this->drawFunc = drawFunc;
}