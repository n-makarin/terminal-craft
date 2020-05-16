#!/bin/sh

#  run.sh
#  terminal-craft
#
#  Created by Nikita Makarin on 16.05.2020.
#  Copyright © 2020 Nikita Makarin. All rights reserved.

g++ main.cpp -o main -std=c++17 -lncurses
wait
./main
