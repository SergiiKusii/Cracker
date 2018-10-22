#include "Logger.h"
#include <iostream>

std::unique_ptr<Logger> Logger::m_instance;

Logger* Logger::Get()
{
    if (!m_instance)
    {
        m_instance = std::unique_ptr<Logger>(new Logger());
    }

    return m_instance.get();
}

void Logger::Info(const std::string& msg)
{
    Log(LogType::info, msg);
}
void Logger::Error(const std::string& msg)
{
    Log(LogType::error, msg);
}

void Logger::Log(const LogType type, const std::string& msg)
{
    switch (type)
    {
    case LogType::error:
        std::cout << "ERROR: ";
        break;
    case LogType::info:
        std::cout << "INFO: ";
        break;  
    default:
        break;   
    }

    std::cout << msg << std::endl;
}