#pragma once

#include <string>

class ProgressBar
{
public:
    ProgressBar(const uint64_t size = 100);
    ~ProgressBar();
    void operator++();
    void setProgress(const uint64_t progress);

private:
    uint64_t m_size;
    uint64_t m_progress;
};