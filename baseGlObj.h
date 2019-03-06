#pragma once
class baseGlObj
{
protected:
	int x, y, w, h;
	bool wannaDraw;
	void(*drawFunc)(int, int, int, int);
	void(*click)(int, int);
public:
	baseGlObj(int x, int y, int w, int h);
	void setX(int x);
	void setY(int y);
	void setWidth(int w);
	void setHeight(int h);
	void setWannaDraw(bool wanna);
	void setDrawFunc(void(*drawFunc)(int, int, int, int));
	void draw();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	bool getWannaDraw();
	bool isInRange(int x, int y);
	bool isWannaDraw();
	void setOnClick(void(*click)(int, int));
	void onClick(int btn, int state);
};