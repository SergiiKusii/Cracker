#pragma ones

#include <memory>
#include <string>

enum class LogType
{
    none,
    info,
    error
};

class Logger
{
public:
    static Logger* Get();

    void Info(const std::string& msg);
    void Error(const std::string& msg);

    void Log(const LogType type, const std::string& msg);

private:
    static std::unique_ptr<Logger> m_instance;
    
    Logger() = default;
};