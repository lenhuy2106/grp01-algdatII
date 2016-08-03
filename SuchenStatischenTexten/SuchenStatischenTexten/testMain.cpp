
#include <iostream>
#include "TheText.h"
#include "DirFileSearch.h"

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


  DirFileSearch testDir;

  for (auto &&item :testDir.files()) {
    std::cout << item << std::endl;
  }

  std::vector<std::string> files = testDir.files();
  auto result = testDir.exactSearch("der");

  for (auto &&element : result) {
    std::cout << "Count of 'der': "  << element.second << " in file: " << element.first << std::endl;
  }

  /*for (unsigned int index = 0; index < result.size(); ++index) {
    std::cout << "Count of 'der': "  << result.at(index) << " in file: " << files.at(index) << std::endl;
  }
*/
  return 0;
}