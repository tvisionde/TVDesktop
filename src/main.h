#pragma once

#include "pch.h"
#include "gadgets.h"

class TStatusLine;
class TMenuBar;
class TEvent;
class TPalette;

enum commands {
    cmHideWindow,
    cmRestart,
    cmAbout,
    cmShutDown,
    cmOpenApp,
    cmEventLogs
};

enum hcs {
    hcOpenApp,
    hcSaveSession,
    hcOpenSession
};

const auto kbAltShiftR = TKey('R', kbAltShift);

class TTVDesktopApp: public TApplication
{
private:
    TClockView *clock;

    void aboutDlgBox();

public:
    TTVDesktopApp( int argc, char** argv );
    static TStatusLine *initStatusLine( TRect r );
    static TMenuBar *initMenuBar( TRect r );
    virtual void handleEvent( TEvent& evt );
    virtual void idle();
};