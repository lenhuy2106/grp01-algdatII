#ifndef IOPARSER_H
#define IOPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>

class IOHelper{
 public:
/**
 * Helper function for loading text.
 * @param file Readin file.
 * @return File in string format.
 */
  static std::string IOImport(const std::string file){
    std::string input = "";

    std::ifstream read(file);
    std:: string tmp;
    while (!read.eof()) {
      getline(read, tmp);
      input.append(tmp);
    }
    //std::cout << input << std::endl;

    return input;
  }

/**
 * String splitter.
 * @param input The String.
 * @return Seperated words.
 */
  static std::vector<std::string> splitString(const std::string input){
    std::istringstream iss(input);
    std::vector<std::string> tokens;
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(tokens));

    return tokens;
  }
};

#endif //IOPARSER_H