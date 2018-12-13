#include "ConsoleRender.h"
#include "ProgressBar.h"

void ConsoleRender::Draw(const Document& doc) 
{
    if (!m_progressBar)
    {
        m_progressBar = std::make_unique<ProgressBar>(doc.count_need);
    }

    m_progressBar->setProgress(doc.count_done);
}

