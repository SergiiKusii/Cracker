#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <shadow.h>
#include <paths.h>

#include "ShadowRow.h"

namespace Constants
{
    static const char fieldSeparator = ':';
    static const char passwordSeparator = '$';
    static const int paswordFieldMinSize = 1 + 2;
    static const std::set<std::string> lockedPasswords = {"*", "!", "!!"};  
    static const std::map<std::string, HashType> hashTypeMap = {
        {"1", HashType::md5},
        {"2a", HashType::blowfish_a},
        {"2y", HashType::blowfish_y},
        {"5", HashType::sha256},
        {"6", HashType::sha512},
    };
}

static std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

static HashType GetHashType(const std::string& str)
{
#ifdef _TRACE_MODE
    std::cout << "GetHashType(" << str << ")" << std::endl;
#endif 
    auto it = Constants::hashTypeMap.find(str);
    if (it != Constants::hashTypeMap.end())
    {
        return it->second;
    }

    return HashType::none;
}

ShadowRow::ShadowRow(struct spwd* pspwd)
{
    SetPassword(pspwd->sp_pwdp);
}

void ShadowRow::SetPassword(const std::string& str)
{
    if (Constants::lockedPasswords.find(str) != Constants::lockedPasswords.end())
    {
        m_password.isLocked = true;
        return;
    }

    auto fields = split(str, Constants::passwordSeparator);
    if(fields.size() < Constants::paswordFieldMinSize)
    {
        throw std::runtime_error("Cannot parse password " + str);
    }
    size_t idx = 1; // first index empty string
    auto hashTypeStr = fields[idx++];
    m_password.type = GetHashType(hashTypeStr);
    if (m_password.type == HashType::none)
    {
        throw std::runtime_error("Cannot get hash type " + hashTypeStr);
    }

    m_password.saltPrefix = Constants::passwordSeparator + hashTypeStr + Constants::passwordSeparator;

    if (fields.size() > Constants::paswordFieldMinSize)
    {
        m_password.salt = fields[idx++];
    }

    m_password.hash = fields[idx++];
}

PasswordHashInfo ShadowRow::GetPasswordHashInfo()
{
    return m_password;
}
