
Cracker - application for get passwords from /etc/shadow file 

boost 1.66:
apt-get install libboost-dev

Installing boost 1.66 in Ubuntu 

Download Boost from official source https://www.boost.org/doc/libs/1_66_0/more/getting_started/unix-variants.html
Extract it
Open terminal and cd to extracted dir
run "./bootstrap.sh --help" command to see help
Then run "./bootstrap.sh" command it will take some time to build
Then run "sudo ./b2 --with-test --with-program_options --prefix=<path to install> install" to install boost.
The default installation location are "/usr/local/inlcude/boost" for header files and "/usr/local/lib" for compiled libraries
If we install boost in custom location we need to set BOOST_ROOT=<path to install>

crypto++:
apt-get install libcrypto++8 libcrypto++8-dbg libcrypto++-dev
