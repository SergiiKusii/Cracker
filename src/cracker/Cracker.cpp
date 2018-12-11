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
    std::string error;
    for (size_t currLen = 1; currLen <= g_passwordMaxLen; currLen++)
    {
        boost::asio::post(pool, [&password, &passwordHashInfo, currLen, &error](){
            try
            {
                auto unhesher = CreateUnhesher(g_unhesherType);
                auto currPassword = unhesher->Unhesh(passwordHashInfo, {currLen, currLen});
                LOGD  << "thread { " << currLen << ", " << currLen << "}";
                if (!currPassword.empty())
                {
                    UnhesherBase::StopAll();
                    password = currPassword;
                }
            }
            catch (const std::exception& ex)
            {
                UnhesherBase::StopAll();
                error = ex.what();
            }
        });
    }

    pool.join(); 

    UnhesherBase::StopAll(false);

    if (!error.empty())
    {
        throw std::runtime_error(error);
    }

    return password;
}
