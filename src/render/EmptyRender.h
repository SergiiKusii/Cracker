#pragma once

#include "IRender.h"

class EmptyRender : public IRender
{
public:
    virtual void Draw(const Document& doc) override
    { }
};