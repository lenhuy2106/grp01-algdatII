//
// Created by falknor on 27.07.16.
//

#ifndef SEARCHIT_TEXTWORD_H
#define SEARCHIT_TEXTWORD_H

#include "SufTree.h"
class TextWord {
 private:
  const unsigned long length;
  int count;
  const std::string value;
  const SufTree matchTree;
 public:
  TextWord(const std::string word): value(word), length(word.length()),matchTree(word), count(1){
    std::cout << "+++ Created new Entry with " << word << std::endl;
  }

  bool addInstance(const std::string word);

  bool exactMatch(const std::string word);

  bool partialMatch(const std::string word);

  std::string word() const;
  int wordCount() const;

  void status();

};

#endif //SEARCHIT_TEXTWORD_H
