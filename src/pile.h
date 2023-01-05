//
// Created by evag on 20/12/22.
//

#ifndef SINGE_PILE_H
#define SINGE_PILE_H

#include "pNode.h"
#include "tree.h"

struct Pile
{
    pNode * last;
};

/**
 * @brief Checks if the Pile is empty or not
 * @param pile
 * @return Boolean value. If true, the Pile is empty.
 */
bool is_pile_empty(const Pile &pile);


/**
 * @brief Returns the head node.
 * @param pile
 * @return Pointer to a pNode variable
 */
pNode * head(const Pile &pile);


/**
 * @brief Adds a Tree in the Pile
 * @param pile
 * @param tree
 */
void add(Pile &pile, Tree * tree);

/**
 * @brief Remove a Tree from the Pile
 * @param pile
 */
void remove(Pile &pile);

/**
 * @brief Destroys every dynamically allocated struct in the Pile
 */
void destroy(Pile &pile);

#endif //SINGE_PILE_H
