#include "UnhesherBase.h"
#include <atomic>

static UnhesherRange PasswordCharacters = {32, 126}; // from ' ' to '~' in ascii table
static std::atomic<bool> g_stop(false);

void UnhesherBase::StopAll()
{
    g_stop = true;
}

std::string UnhesherBase::Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& range)
{
    for(size_t i = range.start; i <= range.end; ++i)
    {
        
    }

    return std::string();
}
