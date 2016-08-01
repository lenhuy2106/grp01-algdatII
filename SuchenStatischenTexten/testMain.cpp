
#include <iostream>
#include <fstream>
#include "TheText.h"

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

  TheText testText("input.txt");

  std::cout << "Total number of words: " << testText.wordCount() << std::endl;

  std::cout << "Count of 'der': " << testText.exactMatchCount("der") << std::endl;




  return 0;
}