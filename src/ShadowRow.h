#pragma once
#include <string>
#include "Common.h"

struct ShadowPassword
{
    HashType type;
    std::string salt;
    std::string hash;
};

class ShadowRow
{
public:
    explicit ShadowRow(const std::string& row);

private:
    void SetPassword(const std::string& str);

private:
    std::string m_userName;
    ShadowPassword m_password;
    bool m_isLocked = false;
};