#pragma once
#include <iostream>
#include <string>

#define BLACK 16
#define DARK_GRAY 234
#define GRAY 240
#define SILVER 254
#define WHITE 255
#define YELLOW 11
#define ORANGE 208
#define RED 196
#define PINK 213
#define MAGENTA 207
#define PURPLE 135
#define NAVY 21
#define BLUE 33
#define CYAN 45
#define TEAL 37
#define AQUA 80
#define BROWN 88

using namespace std;

namespace color {

    string set(int id) {
        return string("\e[38;5;" + to_string(id) + "m");
    }

    string reset() {
        return string("\e[0m");
    }

    void print(string text, int color, char endl='\n') {
        cout << set(color) << text << reset() << endl;
    }
}

using color::print;