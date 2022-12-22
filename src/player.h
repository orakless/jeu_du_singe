//
// Created by evag on 20/12/22.
//

#ifndef SINGE_PLAYER_H
#define SINGE_PLAYER_H

#include "types_const.h"

struct Player {
    char type;
    uint score;
    uint id;
};

/**
 * @brief Returns whether the Player is an human or not.
 * @param player
 * @return A boolean value. True if it is an human, false if it is not.
 */
bool is_human(Player &player);

#endif //SINGE_PLAYER_H
