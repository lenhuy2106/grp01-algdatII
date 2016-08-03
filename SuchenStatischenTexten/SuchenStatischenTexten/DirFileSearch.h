//
// Created by falknor on 02.08.16.
//

#ifndef SEARCHIT_DIRFILESEARCH_H
#define SEARCHIT_DIRFILESEARCH_H

#include <string>
#include <vector>

#include <dirent.h>
#include "TheText.h"

#include <map>

/**
 * Class used for searching in a directory.
 */
class DirFileSearch {
 private:
  /**
   * All readin files.
   */
  std::vector<TheText> allFiles;
 public:
  /**
   * Constructor.
   * @param folderPath Path used for search.
   * @return A initialized DirFileSearch object.
   */
  DirFileSearch(const std::string folderPath = ".", std::string fileExtension = ".txt");

  /**
   * The count of the searched word in all files.
   * @param word The searched word.
   * @return
   */
  std::map<std::string, unsigned int> exactSearchCount(const std::string word);

  std::map<std::string, std::vector<unsigned int>> exactSearchOccurances(const std::string word);

  /**
   * Add a new file for the search.
   * @param fileName The file.
   */
  void addFile(const std::string fileName);

  /**
   * A list of all contained files.
   * @return The list.
   */
  std::vector<std::string> files();
};

#endif //SEARCHIT_DIRFILESEARCH_H
