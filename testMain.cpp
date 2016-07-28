
#include <iostream>
#include <fstream>
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
  if (test.partialMatch("b")) {
    std::cout << "found b" << std::endl;
  }
  if (test.partialMatch("xlub")) {
    std::cout << "found xlub!!! error" << std::endl;
  }
  if (test.partialMatch("lub")) {
    std::cout << "found lub" << std::endl;
  }
  if (test.partialMatch("blub")) {
    std::cout << "found blub" << std::endl;
  }
  
  test.status();

  std::ifstream testFile;

  char tmp[255];
  testFile.open("./Readme.md");

  if(testFile.is_open()) {
    std::cout << "reading test file:" << std::endl;

    while (!testFile.eof()) {
      testFile.getline(tmp,255);
      std::cout << tmp;
    }

  }



  return 0;
}