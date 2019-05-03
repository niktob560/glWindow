#ifndef _BASEGLOBJ_DEFINED
#define _BASEGLOBJ_DEFINED

class BaseGlObj
{
private:
protected:
    int x, y, w, h;
    void (*drawerFunc)(int w, int h) = 0x00;
    void (*drawEnderFunc)() = 0x00;
    BaseGlObj* rootObject = 0x00;
    void (*keyPressedHandleFunc)(unsigned char key, int x, int y) = 0x00;
    void (*mouseClickedHandleFunc)(int button, int state, int x, int y) = 0x00;
    int objectId = 0;
public:
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
    void setDrawerFunc(void (*drawerFunc)(int w, int h));
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
};

#endif
