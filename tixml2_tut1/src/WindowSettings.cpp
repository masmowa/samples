#include "WindowSettings.h"

WindowSettings::WindowSettings(const std::string& name, unsigned int x, unsigned int y, unsigned int cx, unsigned int cy)
: _x(x)
, _y(y)
, _cx(cx)
, _cy(cy)
, _name(name.c_str())
{
    //ctor
}

WindowSettings::~WindowSettings()
{
    //dtor
}
