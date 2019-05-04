#include "button.hpp"


BaseGlButton::BaseGlButton(int x, int y, int w, int h, BaseGlObj* rootObject, std::wstring text) : BaseGlObj(x, y, w, h, rootObject)
{
    this->text = text;
}


void BaseGlButton::setType(int type)
{
    this->type = type;
}

void BaseGlButton::setText(std::wstring text)
{
    this->text = text;
}

int BaseGlButton::getType()
{
    return type;
}

std::wstring BaseGlButton::getText()
{
    return text;
}
