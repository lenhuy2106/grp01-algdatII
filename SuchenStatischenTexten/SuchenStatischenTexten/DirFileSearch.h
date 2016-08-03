//
// Created by falknor on 02.08.16.
//

#ifndef SEARCHIT_DIRFILESEARCH_H
#define SEARCHIT_DIRFILESEARCH_H

#include <string>
#include <vector>

#include <dirent.h>
#include "TheText.h"
class DirFileSearch {
 private:
  std::vector<TheText> allFiles;
 public:
  DirFileSearch(const std::string folderPath = ".");

  std::vector<int> exactSearch(const std::string word);

  std::vector<std::string> files();
};

#endif //SEARCHIT_DIRFILESEARCH_H
