#pragma once

#include "UnhesherBase.h"

enum class UnhesherType
{
    native,
    crypto
}

UnhesherGuard CreateUnhesher(const UnhesherType type);