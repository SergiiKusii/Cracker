#pragma once
#include <string>
#include "Common.h"

struct spwd;

class ShadowRow
{
public:
    explicit ShadowRow(struct spwd* pspwd);
    PasswordHashInfo GetPasswordHashInfo();
private:
    void SetPassword(const std::string& str);

private:
    PasswordHashInfo m_password;
};