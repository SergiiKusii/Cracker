#pragma once

#include <string>
#include <vector>
#include "ShadowRow.h"

class ShadowFile
{
public:
    explicit ShadowFile(const std::string& file);

private:
    std::vector<ShadowRow> m_rows;
};