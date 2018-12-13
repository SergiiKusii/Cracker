#include <atomic>
#include <algorithm>
#include <cmath>

#include "UnhesherBase.h"

static constexpr UnhesherRange g_passwordCharacters = {32, 126}; // from ' ' to '~' in ascii table
static constexpr size_t g_charsCount = g_passwordCharacters.end - g_passwordCharacters.start;

static std::atomic<bool> g_stop(false);

uint64_t UnhesherBase::GetCombinationsCount(const size_t passwordLength)
{
    auto res = pow(passwordLength, g_charsCount);
    return static_cast<uint64_t>(res);
}

void UnhesherBase::StopAll(const bool stop)
{
    g_stop = stop;
}

std::string UnhesherBase::Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& range)
{
    auto g_charsCount = g_passwordCharacters.end - g_passwordCharacters.start;
    for(size_t length = range.start; length <= range.end; ++length)
    {
        std::string password;
        std::string bitmask(length, 1); // K leading 1's
        bitmask.resize(g_charsCount, 0); // N-K trailing 0's
        do {

            if (g_stop)
            {
                return std::string();
            }

            for (size_t i = 0; i < g_charsCount; ++i) // [0..N-1] integers
            {
                if (bitmask[i])
                {
                    password.push_back((char)(i + g_passwordCharacters.start));
                }
            }

            auto hash = Crypt(passwordHashInfo.type, passwordHashInfo.salt,  passwordHashInfo.saltPrefix, password);
            if (hash == passwordHashInfo.hash)
            {
                return password;
            }

            password.clear();

        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    }

    return std::string();
}
