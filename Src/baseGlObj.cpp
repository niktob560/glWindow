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

void BaseGlObj::setMouseClickHandler(void (*mouseClickedHandleFunc)(int button, int state, int x, int y))
{
    this->mouseClickedHandleFunc = mouseClickedHandleFunc;
}

void BaseGlObj::setObjectId(int id)
{
    objectId = id;
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

int BaseGlObj::getObjectId()
{
    return objectId;
}




void BaseGlObj::draw()
{
    std::cout << "baseDraw\n";
    if(drawerFunc != 0x00)
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
    // std::cout << "\t" << x << ":" << y << "\n\t\t" << x << ":" << y << "\n";
    //
    // std::cout   << "(x >= 0)-------" << (x >= x) << "\n" << "(x <= w)---" << (x <= x + w) << "\n"
    //             << "(y >= 0)-------" << (y >= y) << "\n" << "(y <= h)---" << (y <= y + h) << "\n";

    return (   x >= 0
            && x <= w
            && y >= 0
            && y <= h);
}

void BaseGlObj::mouseClicked(int button, int state, int x, int y)
{
    if(mouseClickedHandleFunc != 0x00)
        mouseClickedHandleFunc(button, state, x, y);
}



void BaseGlObj::sendMessage(int type, std::map<int, int> data)
{
    switch (type)
    {
        case MSG_TYPE_MOUSE:
        {
            int button, state, x, y;
            for (auto it = data.begin(); it != data.end(); it++)
            {
                switch (it->first)
                {
                    case MSG_PART_BUTTON:
                        button = it->second;
                        break;
                    case MSG_PART_STATE:
                        state = it->second;
                        break;
                    case MSG_PART_X:
                        x = it->second;
                        break;
                    case MSG_PART_Y:
                        y = it->second;
                        break;
                    default:
                        break;
                }
            }
            mouseClicked(button, state, x, y);
            break;
        }
        case MSG_TYPE_KEYBOARD:
        {
            int key, x, y;
            for (auto it = data.begin(); it != data.end(); it++)
            {
                switch (it->first)
                {
                    case MSG_PART_KEY:
                        key = it->second;
                        break;
                    case MSG_PART_X:
                        x = it->second;
                        break;
                    case MSG_PART_Y:
                        y = it->second;
                        break;
                    default:
                        break;
                }
                keyPressed(key, x, y);
            }
            break;
        }
        case MSG_TYPE_UNDEF:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}
