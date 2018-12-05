#include <plog/Log.h>

#include "Cracker.h"

Cracker::Cracker (IRenderGuard&& render)
    : m_render(std::move(render))
{
    
}

std::string Cracker::Crack(const PasswordHashInfo& passwordHashInfo)
{
            //Cryper cryper(HashType::sha512);
        //cryper.Encrypt("123456");
    return std::string();
}
