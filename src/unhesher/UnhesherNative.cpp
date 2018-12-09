#include "UnhesherNative.h"
#include "unistd.h"

std::string UnhesherNative::Crypt(const HashType, const std::string& salt, const std::string& saltPrefix, const std::string& data)
{
    auto hash = crypt(data.c_str(), (saltPrefix + salt).c_str());

    return hash;
}