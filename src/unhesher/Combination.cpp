#include "Combination.h"

 Combination::Combination(const std::string& set, t_executor executor)
    : m_set(set)
    , m_executor(executor)
 {

 }

void Combination::Process(const size_t k, std::string::iterator begin, std::string::iterator end)
{
    m_stop = false;
    std::find_if(begin, end, [&](const char& ch){
        std::string prefix(1, ch);
        ProcessAllKLengthRec(prefix, k - 1);
        return m_stop;
    });

}

// The main recursive method 
// execute all possible  
// strings of length k 
void Combination::ProcessAllKLengthRec(const std::string& prefix, const size_t k)
{
    if (k == 0)  
    { 
        if (!m_executor(prefix))
        {
            m_stop = true;
        } 
        return; 
    } 

    // One by one add all characters  
    // from set and recursively  
    // call for k equals to k-1 
    for (auto ch : m_set) 
    { 
        if (m_stop)
        {
            break;
        }
        // Next character of input added 
        std::string newPrefix = prefix + ch;
        // k is decreased, because  
        // we have added a new character 
        ProcessAllKLengthRec(newPrefix, k - 1);  
    }
}