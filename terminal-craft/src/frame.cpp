//
//  frame.cpp
//  terminal-craft
//
//  Created by Nikita Makarin on 16.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#include "frame.hpp"


// public
void Frame::draw()
{
    Frame::init();
    Frame::set_rows_and_columns_number();
    
    Frame::print();
    
    getch();
    endwin();
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
