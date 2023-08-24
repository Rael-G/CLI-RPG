#include "utils/ConsoleUtils.hpp"

#ifdef __linux__
    const char* ConsoleUtils::clearCommand = "clear";
#else
    const char* ConsoleUtils::clearCommand = "cls";
#endif

void ConsoleUtils::ClearScreen() {
    std::system(ConsoleUtils::clearCommand);
}

void ConsoleUtils::PrintTextSlowly(const std::string& text, int delayMillis) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
    }
}

std::string ConsoleUtils::ScanInput()
{
    std::string str {};
    std::cin >> str;
    return str;
}

std::string ConsoleUtils::ScanLine()
{
    std::string str {};
    std::cin.ignore();
    std::getline(std::cin, str);
    
    return str;
}
