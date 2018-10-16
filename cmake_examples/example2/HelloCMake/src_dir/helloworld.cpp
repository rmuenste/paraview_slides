#include <lib_src.hpp>
#include <iostream>

#ifdef WITH_BOOST
#include <boost/foreach.hpp>
#endif

int main(int argc, char *argv[]) {

#ifdef WITH_BOOST
  std::string hello("Hello from Boost!");
  BOOST_FOREACH(char ch, hello)
  {
    std::cout << ch;
  }
  std::cout << std::endl;
#endif

  sayHello();

}
