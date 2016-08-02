//
// Created by falknor on 31.07.16.
//

#ifndef SEARCHIT_PARSER_H
#define SEARCHIT_PARSER_H

#include <string>
#include <vector>
/**
* Parses text from textfile
*/
class Parser {
 protected:
  std::string m_fileName; /**< File that contains the text */ 
 public:
 	/**
 	* Constructor
 	* @param filename Filename
 	*/
  Parser(std::string fileName) : m_fileName(fileName){};
  /**
  * Parses the Text
  * @return Text als Vector
  */
  virtual std::vector<std::string> parseText() = 0;
};

#endif //SEARCHIT_PARSER_H
