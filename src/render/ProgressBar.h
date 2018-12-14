#pragma once

#include <string>
#include <boost/progress.hpp>

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
    boost::progress_display m_display;
};