/*
    Copyright (C) 1994 Borland International
    Copyright (C) 2024 Le Bao Nguyen
*/

#pragma once

#ifndef Uses_TEvent
#   define Uses_TEvent
#endif

#ifndef Uses_TRect
#   define Uses_TRect
#endif

#ifndef Uses_TView
#   define Uses_TView
#endif

#ifndef Uses_TDrawBuffer
#   define Uses_TDrawBuffer
#endif

#include <tvision/tv.h>


class TClockView : public TView
{
private:
    char lastTime[9];
    char curTime[9];

public:
    TClockView( TRect& r );
    virtual void draw();
    virtual void update();
};