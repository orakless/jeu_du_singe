//
// Created by evag on 22/12/22.
//

#ifndef SINGE_GAME_H
#define SINGE_GAME_H

#include "hstring.h"
#include "player.h"
#include "types_const.h"
#include "tree.h"

struct Game {
    String word;
    uint playerNumber;
    Player * players;
};

/**
 * @brief Converts a c-string to uppercase.
 * @param src
 */
void toupper(char * src);

/**
 * @brief Returns the loser if there's one
 * @param game
 * @return A Player if there's a loser, null if not.
 */
Player * loser(Game &game);

/**
 * @brief Checks if the words exist at the end of a turn
 * @param game
 * @param dictionary
 * @param currentPlayer
 */
void check_word(Game &game, Tree &dictionary, Player &currentPlayer);

/**
 * @brief Show the actual scoreboard
 * @param game
 */
void show_score(Game &game);

/**
 * @brief Asks a player for the word he's thinking about
 * @param game
 * @param dictionary
 * @param playerTurn
 */
void ask_word(Game &game, Tree &dictionary, uint &playerTurn);

/**
 * Initialize a new game of Singe.
 * @param game
 * @param dictionary
 */
void new_game(Game &game, Tree &dictionary);

/**
 * @brief Initializes a game of Singe.
 * @param game
 * @param szPlayers
 */
void initialize(Game &game, Tree &dictionary, const char * szPlayers);

#endif //SINGE_GAME_H
