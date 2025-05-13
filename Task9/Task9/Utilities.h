#pragma once
#include <iostream>
#include <windows.h>
#include <string>

enum class ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
};

inline void printColor(const std::string& text, ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
    std::cout << text << std::endl;
    SetConsoleTextAttribute(hConsole, static_cast<int>(ConsoleColor::White));
}


template <typename T>
T clamp(const T& value, const T& min, const T& max) {
    return (value < min) ? min : (value > max) ? max : value;
}