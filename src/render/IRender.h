#pragma once

#include <memory>

struct Document
{
    uint64_t count_need;
    uint64_t count_done;
};

class IRender
{
public:
    virtual void Draw(const Document& doc) = 0;
};

using IRenderGuard = std::unique_ptr<IRender>;