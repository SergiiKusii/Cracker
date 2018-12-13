#include <boost/asio/thread_pool.hpp>
#include <boost/asio.hpp>

#include <plog/Log.h>

#include "Cracker.h"
#include "UnhesherFabrica.h"

static size_t g_passwordMaxLen = 12;
static UnhesherType g_unhesherType = UnhesherType::native; 

Cracker::Cracker (IRenderGuard&& render)
    : m_render(std::move(render))
{
    
}

std::string Cracker::Crack(const PasswordHashInfo& passwordHashInfo)
{
    boost::asio::thread_pool pool(std::thread::hardware_concurrency());
    std::string password;
    std::string error;
    size_t hendledCombinations = 0;
    std::mutex renderMutex;
    const auto allCombinations = g_passwordMaxLen;
    m_render->Draw({allCombinations, 0});
    for (size_t currLen = 1; currLen <= g_passwordMaxLen; currLen++)
    {
        boost::asio::post(pool, [this, &passwordHashInfo, &password, &error, &hendledCombinations, &renderMutex, allCombinations, currLen](){
            try
            {
                LOGD << " START currLen = " << currLen; 

                auto unhesher = CreateUnhesher(g_unhesherType);
                auto currPassword = unhesher->Unhesh(passwordHashInfo, {currLen, currLen});
                if (!currPassword.empty())
                {
                    UnhesherBase::StopAll();
                    password = currPassword;
                }
                else
                {
                    std::unique_lock<std::mutex> lock(renderMutex);
                    hendledCombinations++;
                    m_render->Draw({allCombinations, hendledCombinations});
                }

                LOGD << "END currLen = " << currLen; 
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
