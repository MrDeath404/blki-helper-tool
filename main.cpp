#include <iostream>
#include <string>
#include <thread>
#include <conio.h>

#ifdef __WIN32__
#include <Windows.h>
#else
#include <stdlib.h>
#endif

#include "color_untils.h"

using namespace std;

void sleep(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void clear() {
#ifdef __WIN32__
    system("cls");
#else
    system("clear");
#endif
}

inline char input = '0';
inline char work_input = input;

void show_option(string text, int number) {

    print("[", GRAY, '\0'); print(to_string(number), SILVER, '\0'); print("] ", GRAY, '\0');
    print(text, work_input == to_string(number).c_str()[0] ? YELLOW : WHITE);
}

void main_menu() {

    show_option("Frist Installation", 1);
    show_option("Update", 2);
    show_option("Lock Bootloader (With BlackIron)", 3);
    show_option("Unlock Bootloader", 4);
    show_option("Critical Unlock", 5);
    show_option("Download Tools (adb, avbroot)", 6);
    show_option("Exit", 7);

    input = getch();

    if (input != '\r') {
        work_input = input;
    }

    if (input == '\r') {
        switch (work_input) {
        case '7':
            exit(0);
        default:
            break;
        }
    }
}

int main() {

    while (true) {

        clear();


        main_menu();


        sleep(10);
    }

    return 0;
}