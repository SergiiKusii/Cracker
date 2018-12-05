#include "UnhesherBase.h"

static UnhesherRange PasswordCharacters = {32, 126}; // ' ' - '~' in ascii table

UnhesherBase::UnhesherBase(const PasswordHashInfo& passwordHashInfo)
    : m_passwordHashInfo(passwordHashInfo)
{

}

std::string UnhesherBase::Unhesh(const UnhesherRange& range)
{
    

    return std::string();
}
