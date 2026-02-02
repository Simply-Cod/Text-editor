#include "terminal.h"
#include <termios.h>
#include <unistd.h>

int TerminalEnableRaw(Terminal *terminal) {
    if (tcgetattr(STDIN_FILENO, &terminal->old_term) == -1)
        return 0;

    terminal->raw_term = terminal->old_term;

    terminal->raw_term.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);             // ICANON = process input without pressing enter
                                                                                // ISIG = disable ctrl-c and ctrl-z
                                                                                // IEXTEN = disable ctrl-o
    terminal->raw_term.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);    // IXON = disable ctrl-s and ctrl-q
                                                                                // ICRNL = ctrl-m and enter read as 13 ctrl-j read as 10
    terminal->raw_term.c_oflag &= ~(OPOST);                                     // OPOST = Output processing (\n does not return to beginning anymore)
    terminal->raw_term.c_cflag |= (CS8);                                        // CS8 = sets char byte to 8 bits

    terminal->raw_term.c_cc[VMIN] = 0;                                          // VMIN = minimum amount of bytes read needs before return.
    terminal->raw_term.c_cc[VTIME] = 1;                                         // VTIME = minimum time before return (0.1 second)

    if (tcsetattr(STDIN_FILENO, TCSANOW, &terminal->raw_term) == -1)
        return 0;
    return 1;
}

int TerminalDisableRaw(Terminal *terminal) {

    if (tcsetattr(STDIN_FILENO, TCSANOW, &terminal->old_term) == -1)
        return 0;

    return 1;
}
