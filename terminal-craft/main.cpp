//
//  main.cpp
//  terminal-craft
//
//  Created by Nikita Makarin on 16.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#include <iostream>
#include "src/xnd/xnd.hpp"
#include "src/frame.hpp"

#define use_xcode_ncurses_debugger

void init();
void await_xcode_ncurses_debugger();
void draw_frame();



int main(int argc, const char * argv[]) {
    init();
    return 0;
}


void init()
{
#ifdef use_xcode_ncurses_debugger
    await_xcode_ncurses_debugger();
#endif
    
    draw_frame();
}

void await_xcode_ncurses_debugger()
{
    Xnd xnd;
    if (!xnd.is_terminal_ready()) {
        exit(0);
    }
}

void draw_frame()
{
    Frame frame;
    frame.draw();
}
