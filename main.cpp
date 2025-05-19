#include <iostream>
#include <string>
#include <thread>

#ifdef __WIN32__
#include <Windows.h>
#else
#include <stdlib.h>
#endif

using namespace std;

void sleep(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void main_menu(char& input) {

    // menu part here

    // color change when input == section number, mean it's selected, enter will accept

    cin >> input;

    // work here

    input = 0;
}

int main() {

    char input;

    while (true) {

        main_menu(input);

        sleep(10);
    }

    return 0;
}