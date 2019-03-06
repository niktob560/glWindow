#pragma once
#include "baseGlObj.h"
#include <vector>
#include <cstdint>
class View : public baseGlObj
{
protected:
	std::vector<baseGlObj> objs;
	uint32_t bgColor;
public:
	View();
	View(int x, int y, int w, int h);
	~View();
	void addObj(baseGlObj obj);
	void setWannaDraw(bool wanna);
	void drawChild();
	void setBgColor(uint32_t color);
	uint32_t getBgColor();
	baseGlObj checkClick(int x, int y);
};