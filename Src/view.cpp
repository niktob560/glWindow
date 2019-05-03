#include <iostream>
#include "view.hpp"

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


View::View() : BaseGlObj()
{
    if(childObjectPool != 0x00)
        delete[] childObjectPool;

    childObjectPool = (BaseGlObj**)malloc(sizeof(BaseGlObj*) * numOfChildObjects);

    for(int i = 0; i < numOfChildObjects; i++)
        childObjectPool[i] = 0x00;

    childObjectsRegistrated = 0;
}


View::View(int x, int y, int w, int h, BaseGlObj* rootObject) : BaseGlObj(x, y, w, h, rootObject)
{
    View();
}



void View::terraformChildObjectPool(int newSize)
{
    if(childObjectPool == 0x00)
    {
        childObjectPool = (BaseGlObj**)malloc(sizeof(BaseGlObj*) * numOfChildObjects);
        std::cout << "creating\n";
    }
    else
    {
        childObjectPool = (BaseGlObj**)realloc(childObjectPool, sizeof(BaseGlObj*) * newSize);
        numOfChildObjects = newSize;
        std::cout << "recreating\n";
    }
}



void View::registrateChildObject(BaseGlObj* childObject)
{
    if(childObjectsRegistrated >= numOfChildObjects)
        terraformChildObjectPool(numOfChildObjects + 20);

    if(childObjectPool == 0x00)
        terraformChildObjectPool(numOfChildObjects);

    childObjectPool[childObjectsRegistrated++] = childObject;
    // childObject->x += x;
    // childObject->y += y;
}



BaseGlObj* View::getChildObject(int index)
{
    if(index < childObjectsRegistrated)
        return childObjectPool[index];
    else
        return NULL;
}
using namespace std;
void View::draw()
{
    // std::cout << "drawing...\n";
    // int thisX = this->x,
    //     thisY = this->y;
    // if(this != rootObject)
    // {
    //     thisX += rootObject->x;
    //     thisY += rootObject->y;
    // }
    drawerFunc(w, h);
        // glTranslatef(x, y, 0);
    for(int i = 0; i < childObjectsRegistrated; i++)
    {
        glPushMatrix();
            cout    << "i: " << i << " xy: " << x << ":" << y
                    << endl  << "\tchxy: "   << childObjectPool[i]->getX()
                                                << ":"  << childObjectPool[i]->getY() << endl;

            glTranslatef(childObjectPool[i]->getX() + x, childObjectPool[i]->getY() + y, 0);
            // std::cout << "draw child " << i << std::endl;
            childObjectPool[i]->draw();
        glPopMatrix();
    }
    drawEnd();
    // glutSwapBuffers();
}

void View::drawEnd()
{
    if(drawEnderFunc != 0x00)
    {
        drawEnderFunc();
    }
}


void View::keyPressed(unsigned char key, int x, int y)
{
    std::cout << "A\n";
    if(containsCoords(x, y))
    {
        std::cout << "A\n";
        for(int i = 0; i < childObjectsRegistrated; i++)
        {
            std::cout << "i:" << i << "\n";
            if(childObjectPool[i]->containsCoords(x, y))
            {
                std::cout << "PRESSED\n";
                childObjectPool[i]->keyPressed(key, x, y);
                return;
            }
        }
        if(keyPressedHandleFunc != 0x00)
            keyPressedHandleFunc(key, x, y);
    }
    else
    {
        std::cout << "fuck\n";
    }
}
