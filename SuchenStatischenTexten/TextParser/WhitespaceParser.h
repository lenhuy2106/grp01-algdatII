//
// Created by falknor on 31.07.16.
//

#ifndef SEARCHIT_WHITESPACEPARSER_H
#define SEARCHIT_WHITESPACEPARSER_H

#include "Parser.h"


static std::string ignoredChars = ",;.:_'#+*!\"§$%&/()=?";
/**
*
*/
class WhitespaceParser : public Parser {
 private:
  bool isIgnoredChar(const char checkedChar);
 public:
  /**
  * @param filename 
  */
  WhitespaceParser(std::string fileName);
  /**
  * @param
  */
  virtual std::vector<std::string> parseText() override;
};

#endif //SEARCHIT_WHITESPACEPARSER_H
