//
// Created by falknor on 27.07.16.
//

#include "SufTree.h"
#include <iostream>
void SufTree::Knot::add(std::string suffix) {
  bool createNewKnot = true;
  if(suffix.empty()){
    this->isLeaf= true;
  } else {
    if(suffix.length()==1){
      nextKnots.push_back(Knot(suffix.front(),true));
    } else {
      for (auto &&next : nextKnots) {
        if (next.match(suffix.front())) {
          next.add(suffix.substr(1));
          createNewKnot = false;
        }
      }
      if (createNewKnot) {
        Knot created(suffix.front(), suffix.length()==1);
        created.add(suffix.substr(1));
        nextKnots.push_back(created);
      }
    }
  }
}

bool SufTree::Knot::match(char testedChar) const{
  return testedChar == element;
}

bool SufTree::Knot::search(const std::string word) const {
  bool result = false;
  if(this->match(word.front())){
    if(word.length() == 1) {
      result = isLeaf;
    } else {
      for (auto &&next : nextKnots) {
        result |= next.search(word.substr(1));
      }
    }
  }
  return result;
}
void SufTree::Knot::print(std::string indent) const {
  std::cout << indent << "Knot value: " << element << " isLeaf=" << isLeaf << std::endl;
  for (auto &&knot : nextKnots) {
    knot.print(indent+"--");
  }
}

void SufTree::print() const {
  std::cout << "++++++++++" << std::endl;
  for (auto &&branch : branches) {
    branch.print("|");
  }
  std::cout << "++++++++++" << std::endl;
}
SufTree::SufTree(const std::string word) {
  std::string subString = word;
  while (!subString.empty()){
    // fuege alle moeglichen suffixe hinzu
    std::cout << subString << std::endl;
    bool createNewBranch = true;
    for (auto &&branch : branches) {
      if (branch.match(subString.front())) {
        if(subString.length()==1){
          branch.add("");
        } else {
          branch.add(subString.substr(1));
        }
        createNewBranch = false;
      }
    }
    if (createNewBranch) {

      Knot created = Knot(subString.front(), subString.length()==1);
      created.add(subString.substr(1));
      branches.push_back(created);
    }
    subString = subString.substr(1);
  }
}

bool SufTree::possibleMatch(const std::string searchedWord) const{
  bool result = false;
  for (auto &&branch : branches) {
    result |= branch.search(searchedWord);
  }
  return result;
}
