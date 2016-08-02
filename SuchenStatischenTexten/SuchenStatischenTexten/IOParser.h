#ifndef IOPARSER_H
#define IOPARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>

/**
 * Helper function for loading text.
 * @param file Readin file.
 * @return File in string format.
 */
std::string IOImport(const std::string file){
	std::string input = "";

	std::ifstream read(file);
	getline(read, input);
	std::cout << input << std::endl;

	return input;
}

/**
 * String splitter.
 * @param input The String.
 * @return Seperated words.
 */
std::vector<std::string> splitString(const std::string input){
	std::istringstream iss(input);
	std::vector<std::string> tokens;
	copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		back_inserter(tokens));

	return tokens;
}

#endif //IOPARSER_H