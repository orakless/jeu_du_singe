//
// Created by evag on 20/12/22.
//

#include <cassert>

#include "tests.h"
#include "../src/file.h"

void test_file()
{
    File testFile{};
    testFile.first = nullptr;
    testFile.last = nullptr;

    Range testRange{};
    testRange.start = 0;
    testRange.end = 10;

    assert (get_range(testRange) == 11);

    add(testFile, testRange);
    Node * testNode = head(testFile);
    assert (get_range(get(testNode)) == 11);

    testRange.start = 5;
    testRange.end = 10;
    assert (get_range(testRange) == 6);

    add(testFile, testRange);
    testNode = head(testFile);
    assert (get_range(get(testNode)) == 11);

    remove(testFile);
    testNode = head(testFile);
    assert (get_range(get(testNode)) == 6);

    destroy(testFile);
}
