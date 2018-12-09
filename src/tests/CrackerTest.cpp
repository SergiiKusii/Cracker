#define BOOST_TEST_MODULE CracerModule
#include <boost/test/unit_test.hpp>
#include <string>

#include "Common.h"
#include "Cracker.h"
#include "EmptyRender.h"
#include "UnhesherFabrica.h"

const std::string g_password1   = "1";
const std::string g_password123 = "123";

const PasswordHashInfo hashInfo1   = {HashType::md5, "12345678", "$1$", "XM4P3PrKBgKNnTaqG9P0T/", false};
const PasswordHashInfo hashInfo123 = {HashType::md5, "12345678", "$1$", "tRy4cXc3kmcfRZVj4iFXr/", false};

BOOST_AUTO_TEST_CASE( UnitTest )
{
   BOOST_CHECK( g_password1 != g_password123 );
}


BOOST_AUTO_TEST_CASE( UnitTest2 )
{
   BOOST_CHECK( g_password1 != g_password123 );
}

// BOOST_AUTO_TEST_CASE( CrackerTest )
// {
//    Cracker cracker(std::make_unique<EmptyRender>());
//    auto password = cracker.Crack(hashInfo1);

//    BOOST_CHECK( g_password1 == password );
// }

BOOST_AUTO_TEST_CASE( UnhesherTest )
{
   auto unhesher = CreateUnhesher(UnhesherType::native);
   auto currPassword = unhesher->Unhesh(hashInfo1, {1, 1});

   BOOST_CHECK( g_password1 == currPassword );
}

BOOST_AUTO_TEST_CASE( UnhesherTest123 )
{
   auto unhesher = CreateUnhesher(UnhesherType::native);
   auto currPassword = unhesher->Unhesh(hashInfo123, {3, 3});

   BOOST_CHECK( g_password123 == currPassword );
}