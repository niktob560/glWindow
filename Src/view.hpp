class View : public BaseGlObj
{
private:
protected:
    BaseGlObj* childObjectPool;
public:
    View(int x, int y, int w, int h) : BaseGlObj(x, y, w, h);
}
