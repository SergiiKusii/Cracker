#pragma once

#include <string>
#include <functional>

using t_executor = std::function<bool(std::string)>;

class Combination
{
public:
    Combination(const std::string& set, t_executor executor);
    void Process(const size_t k);

private:
    void ProcessAllKLengthRec(const std::string& prefix, const size_t k);

private:
    std::string m_set;
    t_executor m_executor;
    bool m_stop = false;
};