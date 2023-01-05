//
// Created by evag on 04/01/23.
//

#include "tests.h"
#include "../src/pile.h"
#include <cstring>
#include <cassert>


void test_pile()
{
    Pile testPile{};
    testPile.last = nullptr;

    Tree testTree{};
    set(testTree, "ONE");

    add(testPile, &testTree);
    assert (strcmp("ONE", get(get(*head(testPile))->value)) == 0);

    Tree testTree2{};
    set(testTree2, "TWO");

    add(testPile, &testTree2);
    assert (strcmp("TWO", get(get(*head(testPile))->value)) == 0);

    remove(testPile);
    assert (strcmp("ONE", get(get(*head(testPile))->value)) == 0);

    destroy(testPile);
}
