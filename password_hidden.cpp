/*
  Program: password_hidden.cpp
  Author: ChatGTP
  Date: 03/04/2024
  Description: This program hides text input as a password.
*/

#include <iostream>
#include "password_hidden.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void disableEcho() {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode &= ~ENABLE_ECHO_INPUT;
    SetConsoleMode(hStdin, mode);
#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

void enableEcho() {
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    mode |= ENABLE_ECHO_INPUT;
    SetConsoleMode(hStdin, mode);
#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

std::string getHiddenPassword() {
    std::string password;
    char ch;

    disableEcho();

    while (1) {
        ch = getchar();

        if (ch == '\n') {
            break;
        }

        password.push_back(ch);
        std::cout << '*';
    }

    std::cout << std::endl;
    enableEcho();

    return password;
}