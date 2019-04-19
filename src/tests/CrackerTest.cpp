#define BOOST_TEST_MODULE CracerModule

#include "TestCommon.h"
#include "Cracker.h"
#include "EmptyRender.h"

BOOST_AUTO_TEST_CASE( CrackerTest1 )
{
   Cracker cracker(std::make_unique<EmptyRender>());
   auto password = cracker.Crack(hashInfo1, 0);

   BOOST_CHECK( g_password1 == password );
}

BOOST_AUTO_TEST_CASE( CrackerTest123 )
{
   Cracker cracker(std::make_unique<EmptyRender>());
   auto password = cracker.Crack(hashInfo123, 0);

   BOOST_CHECK( g_password123 == password );
}
