#include <plog/Log.h>
#include <boost/asio/thread_pool.hpp>
#include <boost/asio.hpp>
#include "Cracker.h"
#include "UnhesherFabrica.h"

static size_t g_passwordMaxLen = 16;
static UnhesherType g_unhesherType = UnhesherType::native; 

Cracker::Cracker (IRenderGuard&& render)
    : m_render(std::move(render))
{
    
}

std::string Cracker::Crack(const PasswordHashInfo& passwordHashInfo)
{
    boost::asio::thread_pool pool(4);
    std::string password;
    size_t prevLen = 1;
    for (size_t currLen = 3; currLen <= g_passwordMaxLen; currLen++)
    {
        boost::asio::post(pool, [&password, &passwordHashInfo, prevLen, currLen](){
            auto unhesher = CreateUnhesher(g_unhesherType);
            auto currPassword = unhesher->Unhesh(passwordHashInfo, {prevLen, currLen});
            if (!currPassword.empty())
            {
                UnhesherBase::StopAll();
                password = currPassword;
            }
        });

        prevLen = currLen + 1; 
    }

    pool.join(); 
            //Cryper cryper(HashType::sha512);
        //cryper.Encrypt("123456");
    return password;
}
