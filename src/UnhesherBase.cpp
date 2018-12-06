#include "UnhesherBase.h"

static UnhesherRange PasswordCharacters = {32, 126}; // from ' ' to '~' in ascii table

// UnhesherBase::UnhesherBase(const PasswordHashInfo& passwordHashInfo)
//     : m_passwordHashInfo(passwordHashInfo)
// {

// }

std::string UnhesherBase::Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& range)
{
    

    return std::string();
}
