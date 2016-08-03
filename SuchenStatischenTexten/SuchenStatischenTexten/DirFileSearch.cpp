//
// Created by falknor on 02.08.16.
//

#include "DirFileSearch.h"

DirFileSearch::DirFileSearch(const std::string folderPath) {
  auto path = opendir(folderPath.data());
  if (path != nullptr) {
    auto file = readdir(path);
    while (file != NULL) {
      if (file->d_type == 8) {
        std::cout << "Reading file: " << file->d_name << " as " << static_cast<int>(file->d_type) << std::endl;
        allFiles.push_back(TheText(file->d_name));
      }
      file = readdir(path);
    }
  }
  std::cout << "Number of readin files: " << allFiles.size() << std::endl;
  for (auto &&file : allFiles) {
    std::cout << file.name() << std::endl;
  }
}

std::vector<int> DirFileSearch::exactSearch(const std::string word) {
  std::vector<int> foundCounts;
  for (auto &&file : allFiles) {
    foundCounts.push_back(file.exactMatchCount(word));
  }
  return foundCounts;
}

std::vector<std::string> DirFileSearch::files() {
  std::vector<std::string> result;
  for (auto &&file : allFiles) {
    result.push_back(file.name());
  }
  return result;
}
