#pragma once
#include <string>
#include "Constants.h"

struct Points
{
    int x, y;
};

class INavigation
{
public:
    virtual void setColor(Constants::Color text, Constants::Color background) = 0;
    virtual void setColor(Constants::Color background) = 0;
    virtual void textThrower(const Points p, const std::string& phrase) = 0;
    virtual void textThrower(const Points p, const char ch) = 0;
    virtual void Do_Sleep(const int time) = 0;
    virtual bool buttonPressed() = 0;
    virtual Constants::Directions whichButtonIsPressed() = 0;
    virtual void SetCursor(const Points p) = 0;
    virtual void WindowInit() = 0;
};