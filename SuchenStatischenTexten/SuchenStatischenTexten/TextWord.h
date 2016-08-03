//
// Created by falknor on 27.07.16.
//


#ifndef SEARCHIT_TEXTWORD_H
#define SEARCHIT_TEXTWORD_H

#include "SufTree.h"

/**
* Represents a single Word 
* Connected to the words suffixtree
*/
class TextWord {
 private:
  const unsigned long length; /**< Length of the word. */
  //int count; /**< Amount of times the word is in text. */
  const std::string value; /**< Word as String. */
  const SufTree matchTree; /**< Word as Suffixtree. */
  std::vector<unsigned int> occurances; /**< All occurances in the text. */
 public:
  /**
  * Constructor
  * @param word Word
  */
  TextWord(const std::string word, const unsigned int index): value(word), length(word.length()),matchTree(word){
    occurances.push_back(index);
    // std::cout << "+++ Created new Entry with '" << word << "'" << std::endl;
  }
  /**
  * Increments the Counter if searched word is exact match
  * @param word searched word
  * @return true if this word is searched word
  */
  bool addInstance(const std::string word, const unsigned int index);
  /**
  * Checks if Word is exacly the searched word
  * @param word searched word
  * @return true if exact match
  */
  bool exactMatch(const std::string word);
  /**
  * Checs if Word is partial match of searched word
  * @param word searched word
  * @return true if partial match
  */
  bool partialMatch(const std::string word);
  /**
  * returns contained word
  */
  std::string word() const;
  /**
  *  Returns how often word is contained in text
  * @return word count
  */
  unsigned int wordCount() const;
  /**
  * prints word, wordcount and tree to console
  */
  void status();

  /**
   * All occurances of the word in the text.
   * @return The indexes in the text.
   */
  std::vector<unsigned int> getOccurances();
};

#endif //SEARCHIT_TEXTWORD_H
