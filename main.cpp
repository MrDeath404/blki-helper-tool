#include <iostream>
#include <string>
#include <thread>
#include <filesystem>
#include <stdlib.h>

#ifdef __WIN32__
#include <conio.h>
#else

#include <termios.h>
#include <unistd.h>
char getch() {

    char buffer = '\0';
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);

    t_new = t_old;
    cfmakeraw(&t_new);

    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    read(STDIN_FILENO, &buffer, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);

    return buffer;
}

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
inline string current_path;

int ctoi(char _char) {
    return static_cast<int>(_char - '0');
}

string execute(string command) {
    char buffer[256];
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return "\0";
    string result;
    while (fgets(buffer, 256, pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

void show_option(string text, int number) {
    print("[", GRAY, '\0'); print(to_string(number), SILVER, '\0'); print("] ", GRAY, '\0');
    print(text, work_input == to_string(number).c_str()[0] ? YELLOW : WHITE);
}

void catch_input(int min, int max) {
    input = getch();
    if (input != '\r' && (min <= ctoi(input) && ctoi(input) <= max)) work_input = input;
}

bool message_text(string message, bool do_clear=true) {

    if (do_clear) clear();

    while (true) {

        print(message, SILVER);
        print("[Y] Yes", work_input == 'y' ? YELLOW : WHITE);
        print("[N] No", work_input == 'n' ? YELLOW : WHITE);

        input = getch();
        if (input != '\r' && (input == 'y' || input == 'n')) work_input = input;

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

    catch_input(1, 7);

    if (input == '\r') {
        switch (work_input) {
        case '1':
            menu_id = (message_text("Starting Frist Installation\nDo you want to continue?") ? 1 : menu_id);
        break;
        case '2':
            menu_id = (message_text("Updating") ? 2 : menu_id);
        break;
        case '3':
            menu_id = (message_text("Locking Bootloader (With BlackIron)") ? 3 : menu_id);
        break;
        case '4':
            menu_id = (message_text("Unlocking Bootloader") ? 4 : menu_id);
        break;
        case '5':
            menu_id = (message_text("Unlocking Bootloader (Critical Section)") ? 5 : menu_id);
        break;
        case '6':
            menu_id = (message_text("Downloading Tools To Work") ? 6 : menu_id);
        break;
        case '7':
            clear();
            exit(0);
        default:
            break;
        }
    }
}

bool check_tools_status() {

    if (!filesystem::is_directory(filesystem::path(current_path + "\bin"))) {
        print("Install Tools first!!!", RED);
        return false;
    }

#ifdef _WIN32_
    if (system(string("set PATH=\"" + current_path + "\bin" + ";%PATH%\"").c_str())) {
        return false;
    }
#else
    if (system(string("export PATH=\"" + current_path + "\bin" + ";$PATH\"").c_str())) {
        return false;
    }
#endif

#ifdef _WIN32_
    if (system("")) {
        
    }
#else

#endif

    return true;
}

bool frist_installation() {
    return true;
}

bool update() {
    return true;
}

bool bl_lock_blki() {
    return true;
}

bool bl_unlock() {
    return true;
}

bool bl_critical_unlock() {
    return true;
}

bool download_tools() {
    print("Section is not ready", RED);
    return true;
}

int main() {
#ifdef __WIN32__
    current_path = execute("cd");
#else
    current_path = execute("pwd");
#endif

    // while (true) {

    //     clear();

    //     switch (menu_id) {
    //         case 0:
    //             main_menu();
    //         break;
    //         case 1:
    //             if (!frist_installation()) {
    //                 if (!message_text("Do you want to retry?")) {
    //                     menu_id = 0;
    //                 }
    //             }
    //             menu_id = 0;
    //         break;
    //         case 2:
    //             if (!update()) {
    //                 if (!message_text("Do you want to retry?")) {
    //                     menu_id = 0;
    //                 }
    //             }
    //             menu_id = 0;
    //         break;
    //         case 3:
    //             if (!bl_lock_blki()) {
    //                 if (!message_text("Do you want to retry?")) {
    //                     menu_id = 0;
    //                 }
    //             }
    //             menu_id = 0;
    //         break;
    //         case 4:
    //             if (!bl_unlock()) {
    //                 if (!message_text("Do you want to retry?")) {
    //                     menu_id = 0;
    //                 }
    //             }
    //             menu_id = 0;
    //         break;
    //         case 5:
    //             if (!bl_critical_unlock()) {
    //                 if (!message_text("Do you want to retry?")) {
    //                     menu_id = 0;
    //                 }
    //             }
    //             menu_id = 0;
    //         break;
    //         case 6:
    //             if (!download_tools()) {
    //                 if (!message_text("Do you want to retry?")) {
    //                     menu_id = 0;
    //                 }
    //             }
    //             menu_id = 0;
    //         break;
    //     }

    //     sleep(10);
    // }

    return 0;
}