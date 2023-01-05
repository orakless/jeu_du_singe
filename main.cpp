#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#include "src/types_const.h"
#include "src/tree.h"
#include "src/game.h"

int main(int argc, const char*argv[])
{
    assert (argc > 1);

    Tree dictionary = {};
    Game game{};

    import(dictionary, DICT_PATH);
    initialize(game, dictionary, argv[1]);

    new_game(game, dictionary);

    destroy(dictionary);
    destroy(game);

    return 0;
}
