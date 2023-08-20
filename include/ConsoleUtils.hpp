#include <iostream>
#include <thread>
#include <chrono>

#pragma once

namespace ConsoleUtils
{
    extern const char* clearCommand;

    void ClearScreen();
    void PrintTextSlowly(const std::string& text, int delayMillis = 100);
}
