#include "ShadowFile.h"
#include <fstream>
#include "stdafx.h"


ShadowFile::ShadowFile(const std::string& file)
{
#ifdef _DEBUG_MODE
    std::cout << "ShadowFile(" << file << ")" << std::endl;
#endif
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