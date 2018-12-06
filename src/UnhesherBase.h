#pragma once

#include <memory>

#include "Common.h"

struct UnhesherRange
{
    size_t start = 0;
    size_t end = 0;
};

class UnhesherBase
{
public:
    UnhesherBase() = default;
    virtual ~UnhesherBase() = default;

    virtual std::string Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& range);

    static void StopAll();

protected:
    virtual std::string Crypt(const HashType, const std::string& salt, const std::string& data) = 0;

protected:
    PasswordHashInfo m_passwordHashInfo;
};

using UnhesherGuard = std::unique_ptr<UnhesherBase>;