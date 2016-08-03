
#include <iostream>
#include "TheText.h"
#include "DirFileSearch.h"

int main(int argc, char const *argv[])
{
  std::cout << "Travis make Test successful." << std::endl;

  TextWord test("blub", 0);

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

  std::cout << "Occurances of 'der':" << std::endl;
  for (auto &&occurance :testText.getOccurances("der")) {
    std::cout << "Index: " << occurance << std::endl;
  }

  DirFileSearch testDir;
  testDir.addFile("Readme.md");

  for (auto &&item :testDir.files()) {
    std::cout << item << std::endl;
  }

  std::vector<std::string> files = testDir.files();
  auto result = testDir.exactSearchCount("der");
  for (auto &&element : result) {
    std::cout << "Count of 'der': "  << element.second << std::endl << "in file: " << element.first << std::endl;
  }

  auto result2 = testDir.exactSearchOccurances("der");
  for (auto &&item2 : result2) {
    std::cout << "Occurances of 'der' " << std::endl;
    if (item2.second.empty()) {
      std::cout << "not found";
    } else {
      for (auto &&occurance : item2.second) {
        std::cout << occurance << ", ";
      }
    }
    std::cout << std::endl << "in file: " << item2.first << std::endl;
  }

  /*for (unsigned int index = 0; index < result.size(); ++index) {
    std::cout << "Count of 'der': "  << result.at(index) << " in file: " << files.at(index) << std::endl;
  }
*/
  return 0;
}