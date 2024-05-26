/*
    Copyright (C) 1994 Borland International
    Copyright (C) 2024 Le Bao Nguyen.
*/

#include <stdlib.h>

#include "utils.h"
#include "gadgets.h"

void TClockView::draw()
{
    TDrawBuffer buf;
    TColorAttr c = getColor(2);

    buf.moveChar(0, ' ', c, (short)size.x);
    buf.moveStr(0, curTime, c);
    writeLine(0, 0, (short)size.x, 1, buf);
}


void TClockView::update()
{
    // using %T will return the same result as %H:%M:%S
    char* currTime = getCurrTimeAndDate("%T");
    strcpy(curTime, currTime);

    if( strcmp(lastTime, curTime) )
    {
        drawView();
        strcpy(lastTime, curTime);
    }
}
