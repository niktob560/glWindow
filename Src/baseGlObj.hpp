#ifndef _BASEGLOBJ_DEFINED
#define _BASEGLOBJ_DEFINED

#include <map>

class BaseGlObj
{
private:
protected:
    int x, y, w, h;
    void (*drawerFunc)(BaseGlObj* owner) = 0x00;
    void (*drawEnderFunc)() = 0x00;
    BaseGlObj* rootObject = 0x00;
    void (*keyPressedHandleFunc)(unsigned char key, int x, int y) = 0x00;
    void (*mouseClickedHandleFunc)(int button, int state, int x, int y) = 0x00;
    int objectId = 0;
public:

    //constants
    static const int   MSG_TYPE_MOUSE   = 1,
                    MSG_TYPE_KEYBOARD   = 2,
                    MSG_TYPE_UNDEF      = 0,
                    MSG_PART_BUTTON     = 1,
                    MSG_PART_KEY        = 1,
                    MSG_PART_X          = 2,
                    MSG_PART_Y          = 3,
                    MSG_PART_STATE      = 4;

    //constructors
    BaseGlObj(int x, int y, int w, int h, BaseGlObj* rootObject);
    BaseGlObj(BaseGlObj* rootObject);
    BaseGlObj();

    //setters
    void setX(int x);
    void setY(int y);
    void setW(int w);
    void setH(int h);
    void setCoords(int x, int y);
    void setSize(int w, int h);
    void setDrawerFunc(void (*drawerFunc)(BaseGlObj* owner));
    void setRootObject(BaseGlObj* rootObject);
    void setDrawEnderFunc(void (*drawEnderFunc)());
    void setKeypressHandler(void (*keyPressedHandleFunc)(unsigned char key, int x, int y));
    void setMouseClickHandler(void (*mouseClickedHandleFunc)(int button, int state, int x, int y));
    void setObjectId(int id);

    //getters
    int getX();
    int getY();
    int getW();
    int getH();
    BaseGlObj* getRootObject();
    int getObjectId();

    //etc funcs
    virtual void draw();
    virtual void drawEnd();
    virtual void keyPressed(unsigned char key, int x, int y);
    virtual void mouseClicked(int button, int state, int x, int y);
    bool containsCoords(int x, int y);
    void sendMessage(int type, std::map<int, int> data);
};

#endif
