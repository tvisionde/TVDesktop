/*
    Copyright (C) 1994 Borland International
    Copyright (C) 2024 Le Bao Nguyen
*/

#pragma once

#ifndef Uses_TView
#   define Uses_TView
#endif

#ifndef Uses_TDrawBuffer
#   define Uses_TDrawBuffer
#endif

#ifndef Uses_TRect
#   define Uses_TRect
#endif

#include <tvision/tv.h>


class TClockView : public TView
{
private:
    char* lastTime = " ";
    char* curTime = " ";

public:
    TClockView(TRect& r): TView(r) {}
    virtual void draw();
    virtual void update();
};