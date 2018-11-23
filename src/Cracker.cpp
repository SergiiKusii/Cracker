#include "stdafx.h"
#include "Logger.h"
#include "ShadowFile.h"
#include "GetspnamWraper.h"
#include "Cryper.h"

namespace Constants
{
    const std::string help = "-h";
}

void PrintHelp()
{
    auto& log =  *Logger::Get();
    log.Log(LogType::none, "Cracker - application for crack linux passwords.\nCopyright Sergii Kusii 2018.");
    log.Log(LogType::none, "Cracker usage:\nCracker [path to shadow file]");
}

int main(int argc, char *argv[])
{
    if( argc != 2 || argv[1] == Constants::help)
    {
        PrintHelp();
        return 0;
    }

    Logger::Get()->Info("Start Cracker!");
    
    try
    {
        //ShadowFile shadowFile(argv[1]);
        //GetspnamWraper getspnamWraper(argv[1]);
        Cryper cryper(HashType::sha512);
        cryper.Encrypt("123456");
    }
    catch (const std::exception& ex)
    {
        Logger::Get()->Error(ex.what());
        return -1;
    }
    
    Logger::Get()->Info("End Cracker!");

    return 0;
}