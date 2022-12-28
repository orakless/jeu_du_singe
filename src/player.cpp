//
// Created by evag on 20/12/22.
//

#include "player.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>


bool is_human(Player &player)
{
    return (player.type == 'H');
}

void get_new_word(Player &player, Tree &tree, char *WORD) {
    assert (!is_human(player));

    if (WORD != nullptr)
    {
        String *newWord = starts_with(tree, WORD);
        if (newWord == nullptr) player.haveAWord = false;
        else player.word = newWord;
    }
    else player.word = tree.value;
}

void get_new_word(Player &player, Tree &tree, String &WORD)
{
    get_new_word(player, tree, get(WORD));
}

char get_next_character(Player &player, String &WORD)
{
    assert (!is_human(player));

    if (player.haveAWord)
    {
        uint size = strlen(get(WORD));
        return get(player.word)[size-1];
    }
    else
    {
        srand(time(nullptr));
        return (char)('A'+rand()%('Z'-'A'));
    }
}

void initialize(Player &player, char type, uint id, Tree &tree)
{
    player.type = type;
    player.id = id;
    player.score = 0;

    if (player.type == 'R')
    {
        player.word = nullptr;
        player.haveAWord = true;
        get_new_word(player, tree, nullptr);
    }
    else
    {
        player.word = nullptr;
        player.haveAWord = false;
    }
}
