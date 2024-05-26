#pragma once

#ifndef Uses_TDialog
#   define Uses_TDialog
#endif

#ifndef Uses_TButton
#   define Uses_TButton
#endif

#include <tvision/tv.h>
#include <json/json.h>
#include <vector>
#include <string>

// Variables for the desktop settings.
Json::Value root;

// Utility functions.
void initializeSettings(void);
char* getCurrTimeAndDate(char* format);
char* getSavePath(char* suffix);

// Windows and dialogs.

class TApplicationsLauncher: public TDialog
{};