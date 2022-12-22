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
 * @brief Destroys every memory dynamically allocated to the Pile.
 */
void destroy(Pile &pile);

#endif //SINGE_PILE_H
