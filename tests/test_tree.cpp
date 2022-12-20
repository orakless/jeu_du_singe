//
// Created by evag on 20/12/22.
//
#include <fstream>
#include <cassert>
#include <iomanip>

#include "tests.h"
#include "../src/tree.h"
#include "../src/types_const.h"

void test_tree()
{
    Tree testTree = {.value = nullptr, .smaller = nullptr, .bigger = nullptr};

    set(testTree, "Hello");
    add(testTree, "World");

    assert(search(testTree, "Hello"));
    assert(search(testTree, "World"));
    assert(!search(testTree, "Faux"));

    destroy(testTree);
}

void test_import_tree()
{
    Tree testTree = {.value = nullptr, .smaller = nullptr, .bigger = nullptr};

    const char PATH[] = "ods4.txt";
    char newWord[MAX_WORD_SIZE] = { 0 };
    import(testTree, PATH);

    std::ifstream in(PATH);
    assert (in);

    while (in)
    {
        in >> std::setw(MAX_WORD_SIZE) >> newWord;
        assert (search(testTree, newWord));
    }
    in.close();
}