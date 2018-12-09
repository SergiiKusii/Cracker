#include "UnhesherNative.h"
#include "unistd.h"

std::string UnhesherNative::Crypt(const HashType, const std::string& salt, const std::string& saltPrefix, const std::string& data)
{
    auto fullSalt = saltPrefix + salt;
    std::string result = crypt(data.c_str(), fullSalt.c_str());

    return fullSalt.size() < result.size() ? result.substr(fullSalt.size() + 1) : "";
}