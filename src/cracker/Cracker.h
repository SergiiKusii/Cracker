#pragma once

#include <string>

#include "Common.h"
#include "IRender.h"

class Cracker
{
public:
    Cracker (IRenderGuard&& render);

    std::string Crack(const PasswordHashInfo& passwordHashInfo, const int threadsCount);

private:
    IRenderGuard m_render;
};