#pragma once

#include "UnhesherBase.h"

class UnhesherNative : public UnhesherBase
{
protected:
   virtual std::string Crypt(const HashType, const std::string& salt, const std::string& data) override;

};