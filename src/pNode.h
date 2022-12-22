//
// Created by evag on 20/12/22.
//

#ifndef SINGE_PNODE_H
#define SINGE_PNODE_H

#include "tree.h"

struct pNode {
    Tree * value;
    pNode * prev;
};

Tree * get(pNode &node);

#endif //SINGE_PNODE_H
