//
// Created by falknor on 31.07.16.
//

#ifndef SEARCHIT_THETEXT_H
#define SEARCHIT_THETEXT_H

#include "TextWord.h"

class TheText {
 private:
  std::vector<TextWord> completeText;
 public:
  TheText(std::string fileName);

  int wordCount();

  int exactMatchCount(const std::string word);
};

#endif //SEARCHIT_THETEXT_H
