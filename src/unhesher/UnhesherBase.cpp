#include <atomic>
#include <algorithm>
#include <numeric>

#include <plog/Log.h>

#include "UnhesherBase.h"
#include "Combination.h"

static constexpr UnhesherRange g_passwordCharacters = {32, 126}; // from ' ' to '~' in ascii table
static constexpr size_t g_charsCount = g_passwordCharacters.end - g_passwordCharacters.start;

static std::atomic<bool> g_stop(false);

static std::string GetPasswordChars()
{
    std::string passwordChars(g_charsCount, ' ');
    std::iota (std::begin(passwordChars), std::end(passwordChars), g_passwordCharacters.start);

    return passwordChars;
}

t_range_container UnhesherBase::GetPartsRange(const size_t partsCount)
{

}

void UnhesherBase::StopAll(const bool stop)
{
    g_stop = stop;
}

std::string UnhesherBase::Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& range)
{
    static std::string passwordChars = GetPasswordChars();
    std::string unheshPassword;
    Combination combo(passwordChars, 
                        [&](std::string password)
                        {
                            if (g_stop)
                            {
                                return false;
                            }

                            auto hash = Crypt(passwordHashInfo.type, passwordHashInfo.salt,  passwordHashInfo.saltPrefix, password);
                            if (hash == passwordHashInfo.hash)
                            {
                                unheshPassword = password;
                                return false;
                            }

                            return true;

                        });

    auto length = range.start;
    while(length <= range.end && unheshPassword.empty() && !g_stop)
    {
        combo.Process(length);
        ++length;
    }

    return unheshPassword;
}
