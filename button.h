#pragma once
#include "baseGlObj.h"
class Button : public baseGlObj
{
protected:
	
public:
	Button(int x, int y, int w, int h, void(*drawFunc)(int, int, int, int));
	Button(int x, int y, int w, int h);
	Button(int x, int y, void(*drawFunc)(int, int, int, int));
	Button(int x, int y);
};