#include <boost/asio/thread_pool.hpp>
#include <boost/asio.hpp>

#include <plog/Log.h>

#include "Cracker.h"
#include "UnhesherFabrica.h"

static const size_t g_passwordMaxLen = 12;
static const UnhesherType g_unhesherType = UnhesherType::native;

Cracker::Cracker (IRenderGuard&& render)
    : m_render(std::move(render))
{
    
}

std::string Cracker::Crack(const PasswordHashInfo& passwordHashInfo)
{
    auto coreCounts = std::thread::hardware_concurrency();
    boost::asio::thread_pool pool(coreCounts);
    std::string password;
    std::string error;
    size_t hendledCombinations = 0;
    auto partsRange = UnhesherBase::GetPartsRange(coreCounts);
    std::mutex renderMutex;
    const auto allCombinations = g_passwordMaxLen * partsRange.size();
    m_render->Draw({allCombinations, 0});
    for (size_t currLen = 1; currLen <= g_passwordMaxLen; currLen++)
    {
        std::for_each(partsRange.begin(), partsRange.end(), [&](const auto& range)
        { 
            boost::asio::post(pool, [&, currLen](){
                try
                {
                    LOGD << " START length = " << currLen 
                         << " parts {" << range.start << ", " << range.end << "}"; 

                    auto unhesher = CreateUnhesher(g_unhesherType);
                    auto currPassword = unhesher->Unhesh(passwordHashInfo, {currLen, currLen}, range);
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

                    LOGD << " END length = " << currLen 
                         << " parts {" << range.start << ", " << range.end << "}"; 
                }
                catch (const std::exception& ex)
                {
                    UnhesherBase::StopAll();
                    error = ex.what();
                }
            });
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
