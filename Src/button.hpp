#ifndef _BASE_GL_BUTTON
#define _BASE_GL_BUTTON
#include "baseGlObj.hpp"
#include <string>

class BaseGlButton : public BaseGlObj
{
private:
protected:
    int type = TYPE_UNDEF;
    std::wstring text = L"";
public:
    //constants
    static const int TYPE_UNDEF = 0;

    //constructors
    BaseGlButton(int x, int y, int w, int h, BaseGlObj* rootObject, std::wstring text);

    //setters
    void setType(int type);
    void setText(std::wstring text);

    //getters
    int getType();
    std::wstring getText();
};

#endif
