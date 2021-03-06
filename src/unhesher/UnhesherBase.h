#pragma once

#include <memory>
#include <vector>

#include "Common.h"

struct UnhesherRange
{
    size_t start = 0;
    size_t end = 0;
};

using t_range_container = std::vector<UnhesherRange>;

class UnhesherBase
{
public:
    UnhesherBase() = default;
    virtual ~UnhesherBase() = default;

    virtual std::string Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& lenRange, const UnhesherRange& symbolsRange);
    virtual std::string Unhesh(const PasswordHashInfo& passwordHashInfo, const UnhesherRange& lenRange);

    static void StopAll(const bool stop = true);

    static t_range_container GetPartsRange(const size_t partsCount);
protected:
    virtual std::string Crypt(const HashType, const std::string& salt, const std::string& saltPrefix, const std::string& data) = 0;

protected:
    PasswordHashInfo m_passwordHashInfo;
};

using UnhesherGuard = std::unique_ptr<UnhesherBase>;