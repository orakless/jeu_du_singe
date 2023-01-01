#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#include "src/types_const.h"
#include "src/hstring.h"
#include "src/tree.h"
#include "tests/tests.h"
#include "src/game.h"

int main(int argc, const char*argv[])
{
    assert (argc > 1);

    Tree dictionary = {};
    Game game{};

    import(dictionary, DICT_PATH);
    initialize(game, dictionary, argv[1]);

    new_game(game, dictionary);

    return 0;
}
