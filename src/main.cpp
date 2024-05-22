#include "main.h"
#include <libtvdesktop/desktop.h>
#include <unistd.h>
#include <sys/reboot.h>

TTVDesktopApp::TTVDesktopApp(int argc, char** argv)
            : TProgInit( &TTVDesktopApp::initStatusLine,
                         &TTVDesktopApp::initMenuBar,
                         &TTVDesktopApp::initDeskTop )
{
    TRect r = getExtent();

    // let's create the clock view
    r.a.x = r.b.x - 9;
    r.b.y = r.a.y + 1;
    clock = new TClockView( r );
    clock->growMode = gfGrowLoX | gfGrowHiX;
    insert( clock );
}

void TTVDesktopApp::handleEvent(TEvent& evt) {
    TApplication::handleEvent(evt);
    switch (evt.what) {
        case evCommand:
            switch (evt.message.command)
            {
                case cmHelp:
                    messageBox("Try to help yourself;-)\n(btw will add later ig?)", mfInformation | mfOKButton);
                    break;

                case cmAbout:
                    aboutDlgBox();
                    break;

                case cmRestart:
                    if (messageBox("Are you sure want to reboot your computer? You will lost all unsaved changes!",
                                   mfConfirmation | mfYesButton | mfNoButton) == cmYes)
                    {
                        seteuid(0);
                        sync();
                        reboot(RB_AUTOBOOT);
                    }
                    break;
            }
            break;
    }
    clearEvent(evt);
}

TStatusLine* TTVDesktopApp::initStatusLine(TRect r) {
    r.a.y = r.b.y - 1;

    return (new TStatusLine(r,
        *new TStatusDef( 0, 50 ) +
            *new TStatusItem( "~F1~ Help", kbF1, cmHelp ) +
            *new TStatusItem( "~Ctrl-C~ Exit", kbCtrlC, cmQuit ) +
            *new TStatusItem( 0, kbAltM, cmCancel)
    ));
}

void TTVDesktopApp::aboutDlgBox() {
    messageBox(
        "\003TvDesktop 0.1.0\n\n" /* \003 centers the line, according to Borland's TvDemo */
        "\003(C) 2024 Le Bao Nguyen.\n\n"
        "\003This is not meant to use in everyday tasks!",
        mfInformation | mfOKButton
    );
}

void TTVDesktopApp::idle() {
    TProgram::idle();
    clock->update();
}

TMenuBar* TTVDesktopApp::initMenuBar(TRect r) {
    r.b.y = r.a.y + 1;
    TSubMenu& mainMenu = \
        *new TSubMenu("\xf0", 0, hcNoContext) +
            *new TMenuItem("About", cmAbout, kbNoKey, hcNoContext, "") +
            *new TMenuItem("Save this session", cmSave, hcSaveSession, "") +
            *new TMenuItem("Load session...", cmLoad, hcLoadSession, "") +
            newLine() +
            *new TMenuItem("Go to command-line", cmDosShell, kbNoKey, hcDosShell, "") +
            *new TMenuItem("Restart computer", cmRestart, kbAltShiftR, hcNoContext, "Alt+Shift+R") +
            *new TMenuItem("Shutdown", cmShutDown, kbNoKey, hcNoContext, "");

    TSubMenu& fileMenu = \
        *new TSubMenu("~F~ile", 0, hcNoContext) +
            *new TMenuItem("New window", cmNew, kbCtrlN, hcNew, "Ctrl+N") +
            *new TMenuItem("Quit", cmQuit, kbAltQ, hcClose, "Alt+Q");
    
    TSubMenu& goMenu = \
        *new TSubMenu("~G~o", 0, hcNoContext) +
            *new TMenuItem("Applications", cmOpenApp, kbF4, hcOpenApp, "F4");
    
    TSubMenu& helpMenu = \
        *new TSubMenu("~H~elp", 0, hcNoContext) +
            *new TMenuItem("Help me!", cmHelp, kbNoKey, hcNoContext, "") +
            *new TMenuItem("Show event logs", cmEventLogs, kbNoKey, hcNoContext, "");
    
    return new TMenuBar(r, mainMenu + fileMenu + goMenu + helpMenu);
}

/*
    The main entrypoint.
*/
int main(int argc, char** argv)
{
    TTVDesktopApp *prog = new TTVDesktopApp(argc, argv);
    prog->run();

    TObject::destroy( prog );
    return 0;
}