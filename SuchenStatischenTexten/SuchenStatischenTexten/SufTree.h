//
// Created by falknor on 27.07.16.
//

#ifndef SEARCHIT_SUFTREE_H
#define SEARCHIT_SUFTREE_H

#include <vector>
#include <string>
#include <iostream>

/**
* Represents a Suffx Tree
* A tree consists of knots
*/
class SufTree {
 private:
  /**
  * Represents a Knot of the Suffixtree
  * Each Knot consists of a char from the word that the tree composes
  */
  class Knot {
   private:
    bool isLeaf; /**< True if Knot is Leaf */  
    const char element; /**< Knot represents this char */  
    std::vector<Knot> nextKnots; /**< Collection of Knots who come after this knot */  
   public:
    /**
    * Constructor
    * @param usedChar Char for knot 
    * @param endPoint True if this knot has no children
    */
    Knot(char usedChar, bool endPoint):element(usedChar), isLeaf(endPoint){
      //std::cout << "Creating new Knot with " << usedChar << " isLeaf=" << isLeaf << std::endl;
    };
    /**
    * Creates new knots
    * @param suffix suffix to add
    */
    void add(std::string suffix);
    /**
    * Matches knot with searched char
    * @param testedChar
    * @return True if Knot contains searched char
    */
    bool match(const char testedChar) const;
    /**
    * Searches word in Tree
    * @param word Word to search
    * @return True if connected Knots compose searched word 
    */
    bool search(const std::string word) const;
    /**
    * Prints out Tree
    * @param indent Word of tree
    */
    void print(std::string indent) const;
  };

  std::vector<Knot> branches;
 public:
  SufTree (const std::string word); /**< Complete Word that the tree represents*/  

  /**
  * Checks if searched Word is found in tree
  * @param searchedWord Searched Word
  * @return True if Tree composes searched Word
  */
  bool possibleMatch(const std::string searchedWord) const;

  /**
  * Prints out tree to Console
  */
  void print() const;
};

//bool unittest1(){
//	SufTree tree("blub");
//	return tree.possibleMatch("blub");
//};

#endif //SEARCHIT_SUFTREE_H
