//
//  frame.cpp
//  terminal-craft
//
//  Created by Nikita Makarin on 16.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#include "frame.hpp"

#define ESC 27
#define KEY_Y 121


// public
void Frame::draw()
{
    Frame::init();
    Frame::set_rows_and_columns_number();
    
    Frame::print();
    

    Frame::set_exit_listener();
    
}

void Frame::set_rows_and_columns_number()
{
    getmaxyx(stdscr, row, col);
}


// private
void Frame::init()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}

void Frame::print()
{
    printw("Your terminal window width is %d, height is %d", row, col);
    refresh();
}

void Frame::exit()
{
    endwin();
    ::exit(0);
}

void Frame::set_exit_listener()
{
    while (1) {
        int ch = getch();
        printw("ch");
        
        if (ch != ESC) {
            continue;
        }
        if (!Frame::confirm_exit()) {
            continue;
        }
        Frame::exit();
    }
}

bool Frame::confirm_exit()
{
    printw("Confirm exit? (y/n)");
    int ch = getch();
    if (ch == KEY_Y) {
        return true;
    }
    return false;
}
