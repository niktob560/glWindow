#include "baseGlObj.h"

baseGlObj::baseGlObj(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void baseGlObj::setX(int x)
{
	this->x = x;
}

void baseGlObj::setY(int y)
{
	this->y = y;
}

void baseGlObj::setWidth(int w)
{
	this->w = w;
}

void baseGlObj::setHeight(int h)
{
	this->h = h;
}

void baseGlObj::setWannaDraw(bool wanna)
{
	wannaDraw = wanna;
}

void baseGlObj::setDrawFunc(void(*drawFunc)(int, int, int, int))
{
	this->drawFunc = drawFunc;
}

int baseGlObj::getX()
{
	return x;
}

int baseGlObj::getY()
{
	return y;
}


int baseGlObj::getWidth()
{
	return w;
}

int baseGlObj::getHeight()
{
	return h;
}

bool baseGlObj::isWannaDraw()
{
	return wannaDraw;
}

void baseGlObj::draw()
{
	drawFunc(x, y, w, h);
}

bool baseGlObj::isInRange(int x, int y)//is dot in range of object
{
	return ((x >= (this->x - (this->w / 2)))
		&& (x <= (this->x + (this->w / 2)))
		&& (y >= (this->y - (this->h / 2)))
		&& (y <= (this->y + (this->h / 2))));
}

void baseGlObj::setOnClick(void(*click)(int, int))
{
	this->click = click;
}

void baseGlObj::onClick(int btn, int state)
{
	if(click != 0);
		click(btn, state);
}