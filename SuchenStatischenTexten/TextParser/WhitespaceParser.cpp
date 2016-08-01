//
// Created by falknor on 31.07.16.
//

#include <fstream>
#include "WhitespaceParser.h"
WhitespaceParser::WhitespaceParser(std::string fileName) : Parser(fileName) {

}

std::vector<std::string> WhitespaceParser::parseText() {
  std::vector<std::string> result;

  std::ifstream inputFile;

  inputFile.open(m_fileName);

  std::string tmpWord = "";

  while (!inputFile.eof()) {
    if(char readChar = inputFile.get() == ' '){
      if(isIgnoredChar(readChar)) {
        // TODO: Implement ignored char handling
      } else {
        result.push_back(tmpWord);
        tmpWord.clear();
      }
    } else {
      tmpWord.push_back(readChar);
    }
  }
  return result;
}

bool WhitespaceParser::isIgnoredChar(const char checkedChar) {
  for (auto &&ignoredChar : ignoredChars) {
    if (ignoredChar == checkedChar) {
      return true;
    }
  }
  return false;
}
