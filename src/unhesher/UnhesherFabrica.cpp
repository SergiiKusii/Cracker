#include "UnhesherFabrica.h"
#include "UnhesherNative.h"
#include "UnhesherExternal.h"

UnhesherGuard CreateUnhesher(const UnhesherType type)
{
    switch (type)
    {
    case UnhesherType::native:
        return std::make_unique<UnhesherNative>();
    case UnhesherType::external:
    default:
        break;
    }

    throw std::runtime_error("Not supported UnhesherType");
}