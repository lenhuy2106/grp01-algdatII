//
// Created by falknor on 31.07.16.
//
#include "TheText.h"

TheText::TheText(std::string fileName) {
  std::vector<std::string> words = splitString(IOImport(fileName));
  std::cout << "####################" << std::endl
            << "# Reading File" << std::endl
            << "####################" << std::endl;
  for (auto &&word  : words) {
    // std::cout << "Adding " << word << " to the list." << std::endl;
    bool existed = false;
    for (auto &&textWord  : completeText) {
      existed |= textWord.addInstance(word);
    }
    if (!existed) {
      completeText.push_back(TextWord(word));
    }
  }
  std::cout << "####################" << std::endl
            << "# Finished reading" << std::endl
            << "####################" << std::endl;
}

int TheText::exactMatchCount(const std::string searchedWord) {
  for (auto &&word : completeText) {
    if(word.exactMatch(searchedWord)) {
      return word.wordCount();
    }
  }
  return 0;
}


int TheText::wordCount() {
  return completeText.size();
}
