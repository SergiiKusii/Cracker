#include "GetspnamWraper.h"
#include <plog/Log.h>
 
#include <shadow.h>
#include <paths.h>

GetspnamWraper::GetspnamWraper(const std::string& file)
{
    struct spwd * currSpwd = getspent();

    auto printSpwd = [](struct spwd * currSpwd)
    {
        if (currSpwd)
        {
            LOGI << std::string(currSpwd->sp_namp) + " " + currSpwd->sp_pwdp;
        }
        else 
        {
            LOGI << "spwd is NULL!";
        }
    };

    printSpwd(currSpwd);

    while (currSpwd)
    {
        currSpwd = getspent();
        printSpwd(currSpwd);
    }

}