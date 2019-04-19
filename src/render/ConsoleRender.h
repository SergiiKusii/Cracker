#pragma once

#include <memory>

#include "IRender.h"
#include "ProgressBar.h"

class ConsoleRender : public IRender
{
public:
    virtual void Draw(const Document& doc) override;

private: 
    std::unique_ptr<ProgressBar> m_progressBar;
};