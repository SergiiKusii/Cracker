#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/MessageOnlyFormatter.h>
#include <iostream>
#include <algorithm> 
#include <iterator> 

#include "ShadowFile.h"
#include "Cracker.h"

namespace Constants
{
    const std::string help = "-h";
}

struct Config
{
    std::string fileName;
    std::string userName;
};

void PrintHelp()
{
    // static plog::ColorConsoleAppender<plog::MessageOnlyFormatter> consoleAppender;
    // plog::init(plog::info, &consoleAppender);

    std::cout << "  Cracker - application for crack linux passwords.\nCopyright Sergii Kusii 2018.\n";
    std::cout << "  Cracker usage:\n    Cracker <path to shadow file> [user name]\n";
}

void PrintResult(const std::string& password)
{
    std::cout << "  Cracked password: " << password << "\n";
}

bool ParseArguments(int argc, char *argv[], Config& cfg)
{
    if( argc < 2 || (argc == 2 && argv[1] == Constants::help))
    {
        PrintHelp();
        return false;
    }

    cfg.fileName = argv[1];

    if (argc == 3)
    {
        cfg.userName = argv[2];
    }

    return true;
}

std::string GetUserName(Users& users)
{
    std::string userName;
    std::cout << "Users list: \n";
    std::copy(users.begin(), users.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << "Input user name from list above, please : ";
    while (userName.empty())
    {
        std::cin >> userName;
        if (users.find(userName) == users.end())
        {
            std::cout << "Wrong user name, type again: ";
            userName.clear();
        }
    }

    return userName;
}

int main(int argc, char *argv[])
{
    Config cfg;
    if (!ParseArguments(argc, argv, cfg))
    {
        return 0;
    }

    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    #ifdef _DEBUG_MODE
    plog::init(plog::debug, &consoleAppender);
    #else
    plog::init(plog::info, &consoleAppender);
    #endif

    LOGD << "Start Cracker";
    
    try
    {
        ShadowFile shadowFile(cfg.fileName);
        
        if (cfg.userName.empty())
        {
            auto users = shadowFile.GetUsers();
            if (users.empty())
            {
                throw std::runtime_error("Cannot find any user in file " + cfg.fileName);
            }
            cfg.userName = GetUserName(users);
        }

        auto hashInfo = shadowFile.GetPasswordHashInfo(cfg.userName);
        LOGD << "User: " << cfg.userName << ", hash: " << hashInfo.hash;

        Cracker cracker;
        auto password = cracker.Crack(hashInfo);

        PrintResult(password);
    }
    catch (const std::exception& ex)
    {
        LOGE << ex.what();
        return -1;
    }
    
    LOGD << "End Cracker";

    return 0;
}