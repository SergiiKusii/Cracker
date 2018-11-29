#include <stdio.h>
#include <exception>
#include <shadow.h>
#include <paths.h>
#include <memory>

#include "ShadowFile.h"
#include "ShadowRow.h"

using file_ptr = std::unique_ptr<FILE, std::function<void(FILE*)>>;

static file_ptr OpenFile(const std::string& fileName)
{   
    FILE* file = fopen (fileName.c_str() , "r");
    if (!file)
    {
        throw std::runtime_error("Cannot open file " + fileName);
    }
    return file_ptr(file, [](FILE* file){ fclose(file); });
}

static void CheckFile(const std::string& fileName)
{
    auto file = OpenFile(fileName); // throw if error
    (void)file;
}

ShadowFile::ShadowFile(const std::string& fileName)
    : m_fileName(fileName)
{
    CheckFile(m_fileName);
}

PasswordHashInfo ShadowFile::GetPasswordHashInfo(const std::string& userName)
{
    auto file = OpenFile(m_fileName);
    struct spwd * currSpwd = NULL;
    
    while ((currSpwd = fgetspent(file.get())) != NULL)
    {
        if (userName == currSpwd->sp_namp)
        {
            ShadowRow shadowRow(currSpwd);
            return shadowRow.GetPasswordHashInfo();
        }
    }

    throw std::runtime_error("Cannot find user " + userName + " in file " + m_fileName);
}

Users ShadowFile::GetUsers()
{
    auto file = OpenFile(m_fileName);
    struct spwd * currSpwd = NULL;
    
    Users users;
    while ((currSpwd = fgetspent(file.get())) != NULL)
    {
        users.emplace(currSpwd->sp_namp);
    }

    return users;
}