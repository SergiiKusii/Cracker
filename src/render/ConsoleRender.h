#pragma once

#include "IRender.h"

class ConsoleRender : public IRender
{
public:
    virtual void Draw(const Document& doc) override;
};