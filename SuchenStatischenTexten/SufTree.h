//
// Created by falknor on 27.07.16.
//
#ifndef SEARCHIT_SUFTREE_H
#define SEARCHIT_SUFTREE_H

#include <vector>
#include <string>
#include <iostream>

class SufTree {
 private:
  class Knot {
   private:
    bool isLeaf;
    const char element;
    std::vector<Knot> nextKnots;
   public:
    Knot(char usedChar, bool endPoint):element(usedChar), isLeaf(endPoint){
      std::cout << "Creating new Knot with " << usedChar << " isLeaf=" << isLeaf << std::endl;
    };
    void add(std::string suffix);
    bool match(const char testedChar) const;
    bool search(const std::string word) const;
    void print(std::string indent) const;
  };

  std::vector<Knot> branches;
 public:
  SufTree (const std::string word);

  bool possibleMatch(const std::string searchedWord) const;

  void print() const;
};

#endif //SEARCHIT_SUFTREE_H
