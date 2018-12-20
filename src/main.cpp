#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/MessageOnlyFormatter.h>
#include <iostream>
#include <algorithm> 
#include <iterator> 
#include <boost/program_options.hpp>

#include "ShadowFile.h"
#include "Cracker.h"
#include "ConsoleRender.h"

namespace Constants
{
    const std::string help = "-h";
}

struct Config
{
    std::string fileName;
    std::string userName;
    int threadsCount = 0;
    bool verbose = false;
    bool debug = false; 
};

void PrintResult(const std::string& password)
{
    if (password.empty())
    {
        std::cout << "  User has no password!" << "\n";
        return;
    }
    std::cout << "  Cracked password: " << password << "\n";
}

bool ParseArguments(int argc, char *argv[], Config& cfg)
{
    using namespace boost::program_options;
    try
    {
        options_description desc{"\
Cracker - application for crack linux passwords.\n\
Copyright Sergii Kusii 2018.\n\n\
Options"};
        desc.add_options()
            ("help,h", "Help screen")
            ("shadow,s", value<std::string>(), "Shadow file name")
            ("user,u", value<std::string>(), "User name")
            ("core,j", value<int>(), "Threads count")
            ("debug,d", "Show debug output")
            ("verbose,v", "Show verbose output");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help") || !vm.count("shadow"))
        {
            std::cout << desc << '\n';
            return false;
        }
                    
        cfg.fileName = vm["shadow"].as<std::string>();
        
        if (vm.count("user"))
        {
            cfg.userName = vm["user"].as<std::string>();
        }

        if (vm.count("core"))
        {
            cfg.threadsCount = vm["core"].as<int>();
        }

        cfg.debug = vm.count("debug") > 0;
        cfg.verbose = vm.count("verbose") > 0;

        return true;
    }
    catch (const error &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return false;
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

    auto logLevel = plog::info;
    if (cfg.verbose)
    {
        logLevel = plog::verbose;
    }
    else if (cfg.debug)
    {
        logLevel = plog::debug;
    }

    plog::init(logLevel, &consoleAppender);

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

        std::string password;
        if (!hashInfo.isLocked){
            Cracker cracker(std::make_unique<ConsoleRender>());
            password = cracker.Crack(hashInfo, cfg.threadsCount);
        }

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