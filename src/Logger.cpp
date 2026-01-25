#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

std::vector<LogEntry> Logger::messages;

std::string CurrentDateTimeToString()
{
    std::time_t currentTimeUTC{std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};
    std::string output(30, '\0');
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&currentTimeUTC));
    return output;
}

void Logger::Log(const std::string &message)
{
    LogEntry entry;
    entry.message = "LOG: [" + CurrentDateTimeToString() + "] - " + message;
    entry.type = LOG_INFO;
    // LOG: [ Date and time ] - message
    std::cout << "\x1B[32m" << entry.message << "\033[0m" << "\n";
    messages.push_back(entry);
}

void Logger::Err(const std::string &message)
{
    LogEntry entry;
    entry.message = "ERROR: [" + CurrentDateTimeToString() + "]" + message;
    entry.type = LOG_ERROR;
    // ERROR: [ Date and time ] - message
    std::cout << "\x1B[32m" << entry.message << "\033[0m" << "\n";
    messages.push_back(entry);
}