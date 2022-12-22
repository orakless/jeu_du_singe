//
// Created by evag on 20/12/22.
//

#include "pile.h"
#include "pNode.h"

void add(Pile &pile, Tree * tree)
{
    pile.last = new pNode{ .value = tree, .prev = pile.last };
}

void remove(Pile &pile)
{
    pNode * nodeToRemove = pile.last;
    pile.last = nodeToRemove->prev;
    delete nodeToRemove;
}

void destroy(Pile &pile)
{
    
}