#include <iostream>
#include "baseGlObj.hpp"


//constructors
BaseGlObj::BaseGlObj()
{
    x = y = w = h = -1;
    drawerFunc = 0x00;
    rootObject = 0x00;
}

BaseGlObj::BaseGlObj(BaseGlObj* rootObject)
{
    BaseGlObj();
    this->rootObject = rootObject;
}

BaseGlObj::BaseGlObj(int x, int y, int w, int h, BaseGlObj* rootObject)
{
    this->rootObject = rootObject;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}




//setters
void BaseGlObj::setX(int x)
{
    this->x = x;
}

void BaseGlObj::setY(int y)
{
    this->y = y;
}

void BaseGlObj::setW(int w)
{
    this->w = w;
}

void BaseGlObj::setH(int h)
{
    this->h = h;
}

void BaseGlObj::setCoords(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void BaseGlObj::setSize(int w, int h)
{
    this->setW(w);
    this->setH(h);
}

void BaseGlObj::setDrawerFunc(void (*drawerFunc)(int w, int h))
{
    this->drawerFunc = drawerFunc;
}

void BaseGlObj::setRootObject(BaseGlObj* rootObject)
{
    this->rootObject = rootObject;
}

void BaseGlObj::setDrawEnderFunc(void (*drawEnderFunc)())
{
    this->drawEnderFunc = drawEnderFunc;
}

void BaseGlObj::setKeypressHandler(void (*keyPressedHandleFunc)(unsigned char key, int x, int y))
{
    this->keyPressedHandleFunc = keyPressedHandleFunc;
}


//getters
int BaseGlObj::getX()
{
    return x;
}

int BaseGlObj::getY()
{
    return y;
}

int BaseGlObj::getW()
{
    return w;
}

int BaseGlObj::getH()
{
    return h;
}

BaseGlObj* BaseGlObj::getRootObject()
{
    return rootObject;
}


void BaseGlObj::draw()
{
    std::cout << "baseDraw\n";
    drawerFunc(w, h);
}

void BaseGlObj::drawEnd()
{
    std::cout << "base draw ending\n";
    if(drawEnderFunc != 0x00)
        drawEnderFunc();
}

void BaseGlObj::keyPressed(unsigned char key, int x, int y)
{
    if(containsCoords(x, y))
        if(keyPressedHandleFunc != 0x00)
            keyPressedHandleFunc(key, x, y);
}

bool BaseGlObj::containsCoords(int x, int y)
{
    int thisX = this->x,
        thisY = this->y;
    if(rootObject != this)
    {
        std::cout << "nice\n";
        thisX += this->x;
        thisY += this->y;
    }
    std::cout << "\t" << x << ":" << y << "\n\t\t" << thisX << ":" << thisY << "\n";

    std::cout   << (x >= thisX) << "\n" << (x <= thisX + w) << "\n"
                << (y >= thisY) << "\n" << (y <= thisY + h) << "\n";

    return (   x >= thisX - w / 2
            && x <= thisX + w / 2
            && y >= thisY - h / 2
            && y <= thisY + h / 2);
}
