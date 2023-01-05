//
// Created by evag on 15/12/22.
//

#ifndef SINGE_NODE_H
#define SINGE_NODE_H

#include "types_const.h"
#include "range.h"
#include <cassert>


struct Node {
    Range currentRange;
    Node * nextNode;
};

/**
 * @brief Gets the Range in the node.
 * @param node
 * @return Range variable (copy)
 */
Range get(Node * node);

#endif //SINGE_NODE_H
