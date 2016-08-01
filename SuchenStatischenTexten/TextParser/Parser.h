//
// Created by falknor on 31.07.16.
//

#ifndef SEARCHIT_PARSER_H
#define SEARCHIT_PARSER_H

#include <string>
#include <vector>
class Parser {
 protected:
  std::string m_fileName;
 public:
  Parser(std::string fileName) : m_fileName(fileName){};
  virtual std::vector<std::string> parseText() = 0;
};

#endif //SEARCHIT_PARSER_H
