#include "stdafx.h"
#include "ShadowFile.h"
#include "GetspnamWraper.h"
#include "Cryper.h"
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/MessageOnlyFormatter.h>

namespace Constants
{
    const std::string help = "-h";
}

void PrintHelp()
{
    static plog::ColorConsoleAppender<plog::MessageOnlyFormatter> consoleAppender;
    plog::init(plog::info, &consoleAppender);

    LOGI << "Cracker - application for crack linux passwords.\nCopyright Sergii Kusii 2018.";
    LOGI << "Cracker usage:\nCracker <path to shadow file> [user name]";
}

int main(int argc, char *argv[])
{
    if( argc != 2 || argv[1] == Constants::help)
    {
        PrintHelp();
        return 0;
    }

    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::info, &consoleAppender);

    LOGI << "Start Cracker!";
    
    try
    {
        //ShadowFile shadowFile(argv[1]);
        //GetspnamWraper getspnamWraper(argv[1]);
        Cryper cryper(HashType::sha512);
        cryper.Encrypt("123456");
    }
    catch (const std::exception& ex)
    {
        LOGE << ex.what();
        return -1;
    }
    
    LOGI << "End Cracker!";

    return 0;
}