#include "view.h"
#include <cstdint>
#include "baseGlObj.h"

void View::addObj(baseGlObj obj)
{
	this->objs.push_back(obj);
}

void View::setWannaDraw(bool wanna)
{
	this->wannaDraw = wanna;
	for(int i = 0; i < this->objs.size(); i++)
	{
		this->objs.at(i).setWannaDraw(wanna);
	}
}

void View::drawChild()
{
	for(int i = 0; i < this->objs.size(); i++)
	{
		this->objs.at(i).draw();
	}
}

View::View(int x, int y, int w, int h) : baseGlObj(x, y, w, h){}
View::View() : baseGlObj(0, 0, 0, 0){}

void View::setBgColor(uint32_t color)
{
	bgColor = color;
}

uint32_t View::getBgColor()
{
	return bgColor;
}

baseGlObj View::checkClick(int x, int y)
{
	for(int i = 0; i < objs.size(); i++)
	{
		if(objs.at(i).isInRange(x, y))
		{
			return objs.at(i);
		}
	}
	return baseGlObj(-1, -1, -1, -1);
}

View::~View()
{
	objs.clear();
}