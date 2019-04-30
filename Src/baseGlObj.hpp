class BaseGlObj
{
private:
protected:
    int x, y, w, h;
    void (*drawerFunc)(int x, int y, int w, int h);
    BaseGlObj* rootObject = 0x00;
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
    void setDrawerFunc(void (*drawerFunc)(int x, int y, int w, int h));
    void setRootObject(BaseGlObj* rootObject);

    //getters
    int getX();
    ing getY();
    ing getW();
    ing getH();
    BaseGlObj* getRootObject();
    
}
