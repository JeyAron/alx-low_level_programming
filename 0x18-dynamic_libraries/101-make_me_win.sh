#!/bin/bash
wget -P .. https://raw.githubusercontent.com/JeyAron/alx-low_level_programming/master/0x18-dynamic_libraries/libscript.so
export LD_PRELOAD="$PWD/../libscript.so"
