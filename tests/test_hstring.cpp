//
// Created by evag on 20/12/22.
//

#include <cassert>
#include <cstring>
#include "tests.h"
#include "../src/hstring.h"

void test_string()
{
    String testString{};
    testString.value = nullptr;
    testString.memUsed = 0;

    set(testString, "Hello");
    assert (strcmp("Hello", get(testString)) == 0);

    set(testString, "Hell");
    assert (strcmp("Hell", get(testString)) == 0);

    append(testString, 'o');
    assert (strcmp("Hello", get(testString)) == 0);

    append(testString, "Hello");
    assert(strcmp("HelloHello", get(testString)) == 0);

    destroy(testString);
}