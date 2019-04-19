#pragma once

#include "UnhesherBase.h"

enum class UnhesherType
{
    native,
    external
};

UnhesherGuard CreateUnhesher(const UnhesherType type);