#include "UnhesherFabrica.h"
#include "UnhesherNative.h"

UnhesherGuard CreateUnhesher(const UnhesherType type)
{
    switch (type)
    {
    case UnhesherType::native:
        return std::make_unique<UnhesherNative>();
    case UnhesherType::crypto:
    default:
        break;
    }

    throw std::runtime_error("Not supported UnhesherType");
}