#pragma once
#include <string>

#include "Common.h"

class Cryper
{
public:
    explicit Cryper(const HashType& type);
    void Encrypt(const std::string& plain);
private:
    HashType m_type;
};