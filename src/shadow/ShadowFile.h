#pragma once

#include <string>
#include <vector>
#include <set>

#include "Common.h"

using Users = std::set<std::string>;

class ShadowFile
{
public:
    explicit ShadowFile(const std::string& file);
    PasswordHashInfo GetPasswordHashInfo(const std::string& userName);
    Users GetUsers();

private:
    std::string m_fileName;
};
