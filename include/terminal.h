#pragma once

#include <termios.h>

typedef struct Terminal {
    struct termios old_term;
    struct termios raw_term;
}Terminal;


int TerminalEnableRaw(Terminal *terminal);
int TerminalDisableRaw(Terminal *terminal);
