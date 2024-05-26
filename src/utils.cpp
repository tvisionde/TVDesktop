#include "utils.h"
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void initializeSettings(void) {
    // read the file
    std::ifstream readfile("", std::ios::binary);
    readfile >> root;
}

// the time format can be looked here: https://cplusplus.com/reference/ctime/strftime/
// ^^^^ put this in the user documentation
char* getCurrTimeAndDate(char* format) {
    time_t raw_time;
    char* result;

    time(&raw_time);
    struct tm* time_info = localtime(&raw_time);
    
    strftime(result, sizeof(result) / sizeof(char*), format, time_info);
    // TODO:                          FIXTHIS^^^^^^
    return result;
}

char* getSavePath(char* suffix) {
    // get the user home path
    char* result;
    if ((result = getenv("HOME")) == NULL) {
        result = getpwuid(getuid())->pw_dir;
    }
    // why not just use std::string idiot?
    return strcat(strcat(result, "/.tvde/savePoints/"), suffix);
}