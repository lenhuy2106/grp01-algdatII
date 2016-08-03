//
// Created by falknor on 31.07.16.
//
#include "TheText.h"

TheText::TheText(std::string fileName) : m_fileName(fileName){
  std::vector<std::string> words = IOHelper::splitString(IOHelper::IOImport(fileName));
  std::cout << "####################" << std::endl
            << "# Reading File" << std::endl
            << "####################" << std::endl;
  for (int index = 0; index < words.size(); ++index)
  //for (auto &&word  : words)
  {
    // std::cout << "Adding " << word << " to the list." << std::endl;
    bool existed = false;
    for (auto &&textWord  : m_completeText) {
      existed |= textWord.addInstance(words.at(index),index);
    }
    if (!existed) {
      m_completeText.push_back(TextWord(words.at(index),index));
    }
  }
  std::cout << "####################" << std::endl
            << "# Finished reading" << std::endl
            << "####################" << std::endl;
}

int TheText::exactMatchCount(const std::string searchedWord) {
  for (auto &&word : m_completeText) {
    if(word.exactMatch(searchedWord)) {
      return word.wordCount();
    }
  }
  return 0;
}


int TheText::wordCount() {
  return m_completeText.size();
}
std::string TheText::name() {
  return m_fileName;
}
