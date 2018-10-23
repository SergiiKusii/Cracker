#include "ShadowFile.h"
#include <fstream>

ShadowFile::ShadowFile(const std::string& file)
{
    std::string line;
    std::ifstream filestream(file);
    if (!filestream.is_open())
    {
        throw std::runtime_error("Cannot open file " + file);
    }
    
    while (std::getline (filestream,line))
    {
        m_rows.emplace_back(line);
    }
    
    filestream.close();
}