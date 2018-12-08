#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include <string>

std::string g_test = "test";

BOOST_AUTO_TEST_CASE( my_test )
{
   BOOST_CHECK( g_test == "test" );
}