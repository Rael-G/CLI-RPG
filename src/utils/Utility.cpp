#include "utils/Utility.hpp"

std::string Utility::GetTime()
{
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;

    return std::to_string(year) + "-" + std::to_string(month) 
        + "-" + std::to_string(day) + " " + std::to_string(hour) + ":" 
        + std::to_string(minute) + "-" + std::to_string(second);
}