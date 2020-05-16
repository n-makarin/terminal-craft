//
//  xnd.hpp
//  terminal-craft
//
//  Created by Nikita Makarin on 16.05.2020.
//  Copyright © 2020 Nikita Makarin. All rights reserved.
//

#ifndef xnd_hpp
#define xnd_hpp

#include <stdio.h>

class Xnd {
    bool has_terminal{false};

public:
    bool is_terminal_ready();
    
private:
    bool is_debugger_attached(int timeout_ms);
};

#endif /* xnd_hpp */
