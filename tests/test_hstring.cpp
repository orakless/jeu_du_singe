//
// Created by evag on 20/12/22.
//

#include <cassert>

#include "tests.h"
#include "../src/hstring.h"

void test_string()
{
    String testString = {.value = nullptr, .memUsed = 0};

    set(testString, "Hello");
}