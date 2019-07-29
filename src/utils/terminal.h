#ifndef TERM_H
#define TERM_H

#include <vector>

#ifdef __linux__
    #include <sys/ioctl.h>
    #include <stdio.h>
    #include <unistd.h>
#else
    #include <windows.h>
#endif

std::vector<int> getTerminalSize()
{
    std::vector<int> size(2);
    #if defined __linux__
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

        size[0] = w.ws_row;
        size[1] = w.ws_col;
    #elif defined _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        size[0] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        size[1] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
        size[0] = -1;
        size[1] = -1;
    #endif

    return size;
}

#endif //TERM_H
