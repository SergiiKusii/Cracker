#define BOOST_TEST_MODULE UnhesherModule

#include "TestCommon.h"
#include "UnhesherFabrica.h"

BOOST_AUTO_TEST_CASE( UnhesherTest1 )
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