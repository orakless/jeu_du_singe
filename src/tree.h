//
// Created by Eva on 14/12/2022.
//

#ifndef SINGE_TREE_H
#define SINGE_TREE_H

#include "hstring.h"

struct Tree
{
    String *value;
    Tree *smaller;
    Tree *bigger;
};

/**
 * @brief Initialize a Tree structure with default values.
 * @param tree The Tree structure to initialize.
 */
void init(Tree &tree);

/**
 * @brief Checks if a Tree have a value.
 * @param tree The Tree
 * @return Boolean value representing if the Tree is empty or not.
 */
bool is_empty(const Tree &tree);

/**
 * @brief Sets the Tree value.
 * @param tree The Tree
 * @param SRC The value
 */
void set(Tree &tree, const char *SRC);

/**
 * @brief Adds a value to the Tree.
 * @param tree The Tree
 * @param SRC The value
 */
void add(Tree &tree, const char *SRC);

/**
 * @brief Searches for a word in the Tree.
 * @param tree The Tree
 * @param SRC The word to search
 * @return True if the word is in the Tree, false if not.
 */
bool search(Tree &tree, const char * SRC);
bool search(Tree &tree, const String &SRC);

/**
 * @brief Import word list from a text file.
 * @param tree The Tree
 * @param PATH The path to the text file
 */
void import(Tree &tree, const char *PATH);

/**
 * @brief Destroys every sub-trees and values of these sub-trees.
 * @param tree The Tree
 */
void destroy(Tree &tree);

#endif //SINGE_TREE_H
