//
//  xnd.cpp (Xcode ncurses debugger)
//  terminal-craft
//
//  Created by Nikita Makarin on 16.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#include "xnd.hpp"
#include <stdlib.h>
#include <ncurses.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>


bool Xnd::is_debugger_attached(int timeout_ms)
{
    fd_set fd_stdin;
    FD_ZERO(&fd_stdin);
    FD_SET(STDIN_FILENO, &fd_stdin);
    struct timespec timeout = {
        timeout_ms / 1000,
        (timeout_ms % 1000) * 1000000
    };

    do {
        errno = 0;
    } while (pselect(STDIN_FILENO + 1, &fd_stdin, NULL, NULL, &timeout, NULL) < 0 &&
           errno == EINTR);

    if (errno != 0) {
        fprintf(stderr, "Unexpected error %d", errno);
        return false;
    }

    return true;
}

bool Xnd::is_terminal_ready()
{
    if (!is_debugger_attached(700)) {
        return 1;
    }

    char *term = getenv("TERM");

    has_terminal = (term != NULL);

    if (has_terminal) {
        has_terminal = (initscr() != NULL);
    }
    
    return has_terminal;
}
