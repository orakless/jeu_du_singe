//
// Created by evag on 20/12/22.
//

#ifndef SINGE_PLAYER_H
#define SINGE_PLAYER_H

#include "hstring.h"
#include "tree.h"
#include "types_const.h"

struct Player {
    char type;
    uint score;
    uint id;
    String * word;
    bool haveAWord;
};

/**
 * @brief Returns whether the Player is an human or not.
 * @param player
 * @return A boolean value. True if it is an human, false if it is not.
 */
bool is_human(Player &player);

/**
 * @brief Gets a new word
 * @param player
 * @param WORD
 * @pre The player is a robot.
 */
void get_new_word(Player &player, Tree &tree, char *WORD);
void get_new_word(Player &player, Tree &tree, String &WORD);

char get_next_character(Player &player, String &WORD);

void initialize(Player &player, char type, uint id, Tree &tree);

#endif //SINGE_PLAYER_H
