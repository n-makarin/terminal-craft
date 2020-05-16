//
//  frame.hpp
//  terminal-craft
//
//  Created by Nikita Makarin on 16.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#ifndef frame_hpp
#define frame_hpp

#include <stdio.h>
#include <iostream>
#include <ncurses.h>

class Frame {
    int row, col;
    
public:
    void draw();
    void set_rows_and_columns_number();
    
private:
    void init();
    void print();
    void exit();
    void set_exit_listener();
    bool confirm_exit();
};

#endif /* frame_hpp */
