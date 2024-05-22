/*
    Copyright (C) 1994 Borland International
    Copyright (C) 2024 Le Bao Nguyen.
*/

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "gadgets.h"

TClockView::TClockView( TRect& r ) : TView( r )
{
    /*
        The long string with spaces has
        the same length with the time format:
        HH:MM:SS
    */
    strcpy(lastTime, "        ");
    strcpy(curTime, "        ");
}


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
    time_t t = time(0);
    char *date = ctime(&t);

    date[19] = '\0';
    strcpy(curTime, &date[11]);

    if( strcmp(lastTime, curTime) )
    {
        drawView();
        strcpy(lastTime, curTime);
    }
}
