#include <iostream>

#include "ProgressBar.h"

namespace Settings
{
    enum eSettings
    {
        barWidth = 70
    };
};

ProgressBar::ProgressBar(const uint64_t size)
    : m_size(size)
    , m_display(size)
    , m_progress(0)
{

}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::operator++()
{
    setProgress(m_progress + 1);
}

void ProgressBar::setProgress(const uint64_t progress)
{
    if (progress > m_size || m_size == 0)
    {
        return;
    }

    size_t increce = 0;
    if (m_progress < progress)
    {
        increce = progress - m_progress;
    }

    m_progress = progress;

    m_display += increce;
}


// void ProgressBar::setProgress(const uint64_t progress)
// {
//     if (progress > m_size || m_size == 0)
//     {
//         return;
//     }
//     m_progress = progress;

//     const uint64_t barProgress = (Settings::barWidth * m_progress) / m_size;

//     std::cout << "[";
        
//     for (int i = 0; i < Settings::barWidth; ++i) {
//         if (i < barProgress) std::cout << "=";
//         else if (i == barProgress) std::cout << ">";
//         else std::cout << " ";
//     }
//     std::cout << "] " << m_progress << "/" << m_size << " " << int(m_progress * 100.0 / m_size) << "% \r";

//     std::cout.flush();
// }
