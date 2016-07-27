
#include <iostream>
#include "SuchenStatischenTexten/SufTree.h"
#include "SuchenStatischenTexten/TextWord.h"

int main(int argc, char const *argv[])
{
  std::cout << "Travis make Test successful." << std::endl;

  TextWord test("blub");

  if (test.exactMatch("b")) {
    std::cout << "found b !!! error" << std::endl;
  }
  if (test.exactMatch("xlub")) {
    std::cout << "found xlub!!! error" << std::endl;
  }
  if (test.exactMatch("blub")) {
    std::cout << "found blub" << std::endl;
  }
  test.status();


  return 0;
}