//
// Created by evag on 15/12/22.
//

#ifndef SINGE_NODE_H
#define SINGE_NODE_H

#include "types_const.h"
#include "range.h"

struct Node {
    Range currentRange;
    Node * nextNode;
};

Range get(Node * node);

#endif //SINGE_NODE_H
