#include <plog/Log.h>
#include <boost/asio/thread_pool.hpp>
#include "Cracker.h"
#include "UnhesherFabrica.h"

static size_t g_passwordMaxLen = 16;
static UnhesherType unhesherType = UnhesherType::native; 

Cracker::Cracker (IRenderGuard&& render)
    : m_render(std::move(render))
{
    
}

std::string Cracker::Crack(const PasswordHashInfo& passwordHashInfo)
{
    // boost::asio::thread_pool pool(4);
    // boost::asio::post(pool, my_task);
    // pool.join(); 
    size_t prevLen = 1;
    for (size_t currLen = 3; currLen <= g_passwordMaxLen; currLen++)
    {
        auto unhesher = CreateUnhesher(unhesherType);
        auto password = unhesher->Unhesh(passwordHashInfo, {prevLen, currLen});

        prevLen = currLen + 1; 
    }
            //Cryper cryper(HashType::sha512);
        //cryper.Encrypt("123456");
    return std::string();
}
