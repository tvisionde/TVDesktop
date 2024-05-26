#pragma once

#ifndef Uses_TApplication
#   define Uses_TApplication
#endif

#ifndef Uses_TEvent
#   define Uses_TEvent
#endif

#ifndef Uses_TDeskTop
#   define Uses_TDeskTop
#endif

#ifndef Uses_TFileDialog
#   define Uses_TFileDialog
#endif

#ifndef Uses_TMenuBar
#   define Uses_TMenuBar
#endif

#ifndef Uses_TSubMenu
#   define Uses_TSubMenu
#endif

#ifndef Uses_TMenuItem
#   define Uses_TMenuItem
#endif

#ifndef Uses_TKeys
#   define Uses_TKeys
#endif

#ifndef Uses_TView
#   define Uses_TView
#endif

#ifndef Uses_TRect
#   define Uses_TRect
#endif

#ifndef Uses_TStatusLine
#   define Uses_TStatusLine
#endif

#ifndef Uses_TStatusDef
#   define Uses_TStatusDef
#endif

#ifndef Uses_TStatusItem
#   define Uses_TStatusItem
#endif

#ifndef Uses_TKeys
#   define Uses_TKeys
#endif

#ifndef Uses_MsgBox
#   define Uses_MsgBox
#endif

#ifndef Uses_fpstream
#   define Uses_fpstream
#endif

#include <tvision/tv.h>

#include "gadgets.h"

// TODO: Sort commands and hcs

enum commands {
    cmHideWindow,
    cmRestart,
    cmAbout,
    cmShutDown,
    cmOpenApp,
    cmEventLogs,
    cmLoad
};

enum hcs {
    hcOpenApp,
    hcSaveSession,
    hcLoadSession
};

const auto kbAltShiftR = TKey('R', kbAltShift);

class TTVDesktopApp: public TApplication
{
private:
    TClockView *clock;
    fpstream *f; // used for (un)saved sessions
    void loadDesktop(std::string which);
    void saveDesktop();
    void aboutDlgBox();

public:
    TTVDesktopApp();
    static TStatusLine *initStatusLine( TRect r );
    static TMenuBar *initMenuBar( TRect r );
    virtual void handleEvent( TEvent& evt );
    virtual void idle();
};