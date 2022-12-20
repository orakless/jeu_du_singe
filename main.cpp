#include <iostream>
#include <fstream>
using namespace std;

#include "src/types_const.h"
#include "src/hstring.h"
#include "src/tree.h"
#include "tests/tests.h"

int main()
{
    Tree newTree = {.value = nullptr,
                    .smaller = nullptr,
                    .bigger = nullptr};

    import(newTree, DICT_PATH);

    String hello = {.value = nullptr, .memUsed = 0}; set(hello, "JOURNAL");

    cout << search(newTree, hello);

    return 0;
}
