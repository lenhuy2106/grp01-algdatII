//
// Created by falknor on 02.08.16.
//

#include "DirFileSearch.h"

DirFileSearch::DirFileSearch(const std::string folderPath, const std::string fileExtension) {
  auto path = opendir(folderPath.data());
  if (path != nullptr) {
    auto file = readdir(path);
    while (file != NULL) {
      if (file->d_type == DT_REG) {
        std::string tmpFile(file->d_name);
        if ( tmpFile.find(fileExtension) != std::string::npos) {
          allFiles.push_back(TheText(file->d_name));
        }
      }
      file = readdir(path);
    }
  }
}

std::map<std::string, unsigned int> DirFileSearch::exactSearchCount(const std::string word) {
  std::map<std::string, unsigned int> foundCounts;
  for (auto &&file : allFiles) {
    foundCounts.insert(std::pair<std::string, unsigned int>(file.name(),file.exactMatchCount(word)));
  }
  return foundCounts;
}

std::map<std::string, std::vector<unsigned int>> DirFileSearch::exactSearchOccurances(const std::string word) {
  std::map<std::string, std::vector<unsigned int>> result;
  for (auto &&file : allFiles) {
    result.insert(std::pair<std::string, std::vector<unsigned int>>(file.name(),file.getOccurances(word)));
  }
  return result;
}

std::vector<std::string> DirFileSearch::files() {
  std::vector<std::string> result;
  for (auto &&file : allFiles) {
    result.push_back(file.name());
  }
  return result;
}
void DirFileSearch::addFile(const std::string fileName) {
  allFiles.push_back(TheText(fileName));
}
