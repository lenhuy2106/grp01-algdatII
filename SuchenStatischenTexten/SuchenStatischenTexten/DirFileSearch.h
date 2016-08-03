//
// Created by falknor on 02.08.16.
//

#ifndef SEARCHIT_DIRFILESEARCH_H
#define SEARCHIT_DIRFILESEARCH_H

#include <string>
#include <vector>

#include <dirent.h>
#include "TheText.h"

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
  std::map<std::string, unsigned int> exactSearch(const std::string word);

  std::vector<std::string> files();
};

#endif //SEARCHIT_DIRFILESEARCH_H
