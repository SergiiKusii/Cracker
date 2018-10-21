#include <iostream>
#include "Logger.h"
#include "ShadowFile.h"

void PrintHelp()
{

}

int main(int argc, char *argv[])
{
    if( argc != 2)
    {
        PrintHelp();
    }

    Logger::Get()->Info("Start Cracker!");
    
    try
    {
        ShadowFile shadowFile(argv[1]);
    }
    catch (const std::exception& ex)
    {
        Logger::Get()->Error(ex.what());
    }
    
    Logger::Get()->Info("End Cracker!");

    return 0;
}