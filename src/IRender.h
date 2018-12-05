#pragma once

#include <memory>

struct Document
{

};

class IRender
{
public:
    virtual void Draw(const Document& doc) = 0;
};

using IRenderGuard = std::unique_ptr<IRender>;