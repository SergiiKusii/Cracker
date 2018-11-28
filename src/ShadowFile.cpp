#include "ShadowFile.h"
#include "stdafx.h"
#include <fstream>

ShadowFile::ShadowFile(const std::string& file)
{
#ifdef _TRACE_MODE
    std::cout << "ShadowFile(" << file << ")" << std::endl;
#endif
    std::string line;
    std::ifstream filestream(file);
    if (!filestream.is_open())
    {
        throw std::runtime_error("Cannot open file " + file);
    }
    

    filestream.close();
}
