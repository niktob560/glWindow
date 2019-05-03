#ifndef _VIEW_DEFINED
#define _VIEW_DEFINED

#include "baseGlObj.hpp"
#include <cstdlib>
#include <cstddef>

class View : public BaseGlObj
{
private:
protected:
    BaseGlObj** childObjectPool = 0x00;
    int numOfChildObjects = 20,
        childObjectsRegistrated = 0;

    void terraformChildObjectPool(int newSize);
public:
    View(int x, int y, int w, int h, BaseGlObj* rootObject);
    View();

    void registrateChildObject(BaseGlObj* childObject);

    BaseGlObj* getChildObject(int index);

    void draw();
    void drawEnd();
    void keyPressed(unsigned char key, int x, int y);
    void mouseClicked(int button, int state, int x, int y);
};

#endif
