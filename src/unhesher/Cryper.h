#pragma once
#include <string>

#include "Common.h"

//Cryper cryper(HashType::sha512);
//cryper.Encrypt("123456");

class Cryper
{
public:
    explicit Cryper(const HashType& type);
    void Encrypt(const std::string& plain);
private:
    HashType m_type;
};