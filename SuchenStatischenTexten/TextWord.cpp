//
// Created by falknor on 27.07.16.
//

#include "TextWord.h"
void TextWord::addInstance(const std::string word) {
    if(this->exactMatch(word)) {
      count += 1;
    }
  }

bool TextWord::exactMatch(const std::string word) {
  std::cout << "Exact Match for '" << value << "' with '" << word <<"'!" << std::endl;
  if(word.length()!= value.length()){
    std::cout << "wrong length!";
    return false;
  } else {
    return matchTree.possibleMatch(word);
  }
}

bool TextWord::partialMatch(const std::string word) {
  std::cout << "Partial Match for '" << value << "' with '" << word <<"'!" << std::endl;
  return matchTree.possibleMatch(word);
}

void TextWord::status() {

  std::cout << "####################" << std::endl << "Word: " << value
            << " Instances: " << count << std::endl;
  matchTree.print();
  std::cout << "####################" << std::endl;
};
