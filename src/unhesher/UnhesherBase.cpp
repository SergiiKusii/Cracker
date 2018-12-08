#include <atomic>
#include <algorithm>

#include "UnhesherBase.h"

static UnhesherRange g_passwordCharacters = {32, 126}; // from ' ' to '~' in ascii table
static std::atomic<bool> g_stop(false);

void UnhesherBase::StopAll()
{
    g_stop = true;
}

std::string UnhesherBase::Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& range)
{
    auto charsCount = g_passwordCharacters.end - g_passwordCharacters.start;
    for(size_t length = range.start; length <= range.end; ++length)
    {
        std::string password;
        std::string bitmask(length, 1); // K leading 1's
        bitmask.resize(charsCount, 0); // N-K trailing 0's
        do {

            if (g_stop)
            {
                return std::string();
            }

            for (size_t i = 0; i < charsCount; ++i) // [0..N-1] integers
            {
                if (bitmask[i])
                {
                    password.push_back((char)(i + g_passwordCharacters.start));
                }
            }

            auto hash = Crypt(passwordHashInfo.type, passwordHashInfo.salt, password);
            if (hash == passwordHashInfo.hash)
            {
                return password;
            }

            password.clear();

        } while (std::prev_permutation(password.begin(), password.end()));
    }

    return std::string();
}

// void comb(int N, int K)
// {
//     std::string bitmask(K, 1); // K leading 1's
//     bitmask.resize(N, 0); // N-K trailing 0's

//     // print integers and permute bitmask
//     do {
//         for (int i = 0; i < N; ++i) // [0..N-1] integers
//         {
//             if (bitmask[i]) std::cout << " " << i;
//         }
//         std::cout << std::endl;
//     } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
// }

// comb(5, 3);

// output

//  0 1 2
//  0 1 3
//  0 1 4
//  0 2 3
//  0 2 4
//  0 3 4
//  1 2 3
//  1 2 4
//  1 3 4
//  2 3 4