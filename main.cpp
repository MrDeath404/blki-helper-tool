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

inline short menu_id = 0;
inline char input = '0';
inline char work_input = input;
inline short progress = 0;

void show_option(string text, int number) {
    print("[", GRAY, '\0'); print(to_string(number), SILVER, '\0'); print("] ", GRAY, '\0');
    print(text, work_input == to_string(number).c_str()[0] ? YELLOW : WHITE);
}

void catch_input() {
    input = getch();
    if (input != '\r') work_input = input;
}

bool message_text(string message, bool do_clear=true) {

    if (do_clear) clear();

    while (true) {

        print(message, SILVER);
        print("\t[Y] Yes", work_input == 'y' ? YELLOW : WHITE);
        print("\t[N] No", work_input == 'n' ? YELLOW : WHITE);

        catch_input();

        if (input == '\r') {
            switch (work_input) {
                case 'y':
                    return true;
                break;
                case 'n':
                    return false;
                break;
            }
        }

        clear();
        sleep(10);
    }

    return false;
}

void main_menu() {

    show_option("Frist Installation", 1);
    show_option("Update", 2);
    show_option("Lock Bootloader (With BlackIron)", 3);
    show_option("Unlock Bootloader", 4);
    show_option("Critical Unlock", 5);
    show_option("Download Tools (adb, avbroot)", 6);
    show_option("Exit", 7);

    catch_input();

    if (input == '\r') {
        switch (work_input) {
        case '1':
            menu_id = (message_text("Starting Frist Installation\nDo you want to continue?") ? 1 : menu_id);
        break;
        case '2':
            menu_id = (message_text("Starting Frist Installation") ? 2 : menu_id);
        break;
        case '3':
            menu_id = (message_text("Starting Frist Installation") ? 3 : menu_id);
        break;
        case '4':
            menu_id = (message_text("Starting Frist Installation") ? 4 : menu_id);
        break;
        case '5':
            menu_id = (message_text("Starting Frist Installation") ? 5 : menu_id);
        break;
        case '6':
            menu_id = (message_text("Starting Frist Installation") ? 6 : menu_id);
        break;
        case '7':
            exit(0);
        default:
            break;
        }
    }
}

bool frist_installation() {
    return true;
}

int main() {

    while (true) {

        clear();

        switch (menu_id) {
            case 0:
                main_menu();
            break;
            case 1:
                if (!frist_installation()) {
                    if (!message_text("Do you want to retry?")) {
                        menu_id = 0;
                    }
                }
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
        }

        sleep(10);
    }

    return 0;
}