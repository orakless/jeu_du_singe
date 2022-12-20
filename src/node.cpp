//
// Created by evag on 15/12/22.
//

#include "node.h"
#include <cassert>

Range get(Node *node)
{
    assert (node != nullptr);
    return node->currentRange;
}