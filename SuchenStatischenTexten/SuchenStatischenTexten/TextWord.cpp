//
// Created by falknor on 27.07.16.
//

#include "TextWord.h"
bool TextWord::addInstance(const std::string word, const unsigned int index) {
  // std::cout << "checking instance with " << word << std::endl;
    if(this->exactMatch(word)) {
      // std::cout << "Incremented " << this->word() << std::endl;
      occurances.push_back(index);
      return true;
    }
  return false;
  }

bool TextWord::exactMatch(const std::string word) {
  if(word.length()!= value.length()){
    // std::cout << "wrong length!" << std::endl;
    return false;
  } else {
    // std::cout << "Exact Match for '" << value << "' with '" << word <<"'!" << std::endl;
    return matchTree.possibleMatch(word);
  }
}

bool TextWord::partialMatch(const std::string word) {
  std::cout << "Partial Match for '" << value << "' with '" << word <<"'!" << std::endl;
  return matchTree.possibleMatch(word);
}

void TextWord::status() {

  std::cout << "####################" << std::endl << "Word: " << value
            << " Instances: " << wordCount() << std::endl;
  matchTree.print();
  std::cout << "####################" << std::endl;
}
std::string TextWord::word() const {
  return value;
}

unsigned int TextWord::wordCount() const {
  return static_cast<unsigned int>(occurances.size());
}
std::vector<unsigned int> TextWord::getOccurances() {
  return occurances;
}
