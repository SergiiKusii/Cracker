#include <atomic>
#include <algorithm>
#include <numeric>
#include <iterator>

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
    t_range_container result;
    if (partsCount == 0 || partsCount == 1)
    {
        result.push_back({0, g_charsCount-1});
        return result;
    }

    if (partsCount >= g_charsCount)
    {
        result.reserve(g_charsCount);
        for(size_t i = 0; i < g_charsCount; ++i)
        {
            result.push_back({i, i});
        }
        return result;
    }

    size_t step = g_charsCount / partsCount;
    size_t end = 0;
    size_t start = 0;
    while(start + step < g_charsCount)
    {
        end = start + step;
        result.push_back({start, end});
        start = end + 1;
    }

    auto rest = g_charsCount - end - 1;
    result.back().end += rest;

    return result;
}

void UnhesherBase::StopAll(const bool stop)
{
    g_stop = stop;
}

std::string UnhesherBase::Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& lenRange)
{
   return Unhesh(passwordHashInfo, lenRange, {0, g_charsCount});
}

std::string UnhesherBase::Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& lenRange, const UnhesherRange& symbolsRange)
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

                            LOGV << "Password: " << password;

                            auto hash = Crypt(passwordHashInfo.type, passwordHashInfo.salt,  passwordHashInfo.saltPrefix, password);
                            if (hash == passwordHashInfo.hash)
                            {
                                unheshPassword = password;
                                return false;
                            }

                            return true;
                        });

    auto length = lenRange.start;
    while(length <= lenRange.end && unheshPassword.empty() && !g_stop)
    {
        combo.Process(length, 
                      std::next(passwordChars.begin(), symbolsRange.start), 
                      std::next(passwordChars.begin(), symbolsRange.end + 1));
        ++length;
    }

    return unheshPassword;
}
