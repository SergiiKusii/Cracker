#include "Logger.h"
#include <iostream>

Logger* Logger::Get()
{
    if (!m_instance)
    {
        m_instance = std::make_unique<Logger>();
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
        std::cout << "ERROR: "
        break;
    case LogType::info:
    default:
        std::cout << "INFO: "
        break;   
    }

    std::cout << msg << std::endl;
}