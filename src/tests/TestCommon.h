#pragma once

#include <boost/test/unit_test.hpp>
#include <string>

#include "Common.h"

const std::string g_password1   = "1";
const std::string g_password123 = "123";

const PasswordHashInfo hashInfo1   = {HashType::md5, "12345678", "$1$", "XM4P3PrKBgKNnTaqG9P0T/", false};
const PasswordHashInfo hashInfo123 = {HashType::md5, "12345678", "$1$", "tRy4cXc3kmcfRZVj4iFXr/", false};