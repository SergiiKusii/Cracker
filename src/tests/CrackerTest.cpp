#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include <string>

#include "Common.h"
#include "Cracker.h"
#include "EmptyRender.h"

std::string g_password123 = "123";

BOOST_AUTO_TEST_CASE( my_test )
{
   PasswordHashInfo hashInfo = {};

   Cracker cracker(std::make_unique<EmptyRender>());
   auto password = cracker.Crack(hashInfo);

   BOOST_CHECK( g_password123 == password );
}