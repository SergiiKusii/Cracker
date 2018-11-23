#include "GetspnamWraper.h"
#include "Logger.h"
 
#include <shadow.h>
#include <paths.h>

GetspnamWraper::GetspnamWraper(const std::string& file)
{
    Logger::Get()->Info(file);

    struct spwd * currSpwd = getspent();

    auto printSpwd = [](struct spwd * currSpwd)
    {
        if (currSpwd)
        {
            Logger::Get()->Info(std::string(currSpwd->sp_namp) + " " + currSpwd->sp_pwdp);
        }
        else 
        {
            Logger::Get()->Info("spwd is NULL!");
        }
    };

    printSpwd(currSpwd);

    while (currSpwd)
    {
        currSpwd = getspent();
        printSpwd(currSpwd);
    }

}