#pragma once

#include <iostream>
#include <thread>
#include <chrono>

class ConsoleUtils
{
    private:
        static const char* clearCommand;

    public:
        static void ClearScreen();
        static void PrintTextSlowly(const std::string& text, int delayMillis = 100);
        static std::string ScanInput();
};
