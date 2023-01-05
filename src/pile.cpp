//
// Created by evag on 20/12/22.
//

#include <cassert>
#include "pile.h"
#include "pNode.h"

bool is_pile_empty(const Pile &pile)
{
    return (pile.last == nullptr);
}

pNode * head(const Pile &pile)
{
    return pile.last;
}

void add(Pile &pile, Tree * tree)
{
    pile.last = new pNode{ .value = tree, .prev = pile.last };
}

void remove(Pile &pile)
{
    assert (!is_pile_empty(pile));

    pNode * nodeToRemove = pile.last;
    if (pile.last->prev != nullptr)
    {
        pile.last = nodeToRemove->prev;
    }
    else
    {
        pile.last = nullptr;
    }
    delete nodeToRemove;
}

void destroy(Pile &pile)
{
    Pile *currentPile = &pile;

    while (!is_pile_empty(pile))
    {
        remove(pile);
    }
}