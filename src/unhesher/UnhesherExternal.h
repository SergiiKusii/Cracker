#pragma once
#include "UnhesherBase.h"

class UnhesherExternal : public UnhesherBase
{
protected:
   virtual std::string Crypt(const HashType, const std::string& salt, const std::string& saltPrefix, const std::string& data) override;

};
