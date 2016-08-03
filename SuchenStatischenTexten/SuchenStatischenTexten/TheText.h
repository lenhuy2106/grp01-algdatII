//
// Created by falknor on 31.07.16.
//

#ifndef SEARCHIT_THETEXT_H
#define SEARCHIT_THETEXT_H

#include "TextWord.h"
#include "IOParser.h"
/**
* Represents the whole text as a model
* This Model contains all word of the text as single objects
*/
class TheText {
 private:
  std::vector<TextWord> m_completeText; /**< Collection of all Words in the text as TextWord Objects */

  std::string m_fileName;
 public:
  TheText(std::string fileName); /**< File that contains the text */  

  /**
  * Counts how many words are in the text
  * @return Amount of words in text
  */
  int wordCount();
  /**
  * Counts exact matches o f searched word in text
  * @param word Searched word
  * @return Amount of exact matches
  */
  int exactMatchCount(const std::string word);

  std::string name();
};

#endif //SEARCHIT_THETEXT_H
