//
// Created by evag on 22/12/22.
//

#include "game.h"


void toupper(char * src)
{
    uint count = 0;
    const char DIFFERENCE = 'A' - 'a';
    while (src[count])
    {
        if (src[count] >= 'a' && src[count] < 'z') src[count] += DIFFERENCE; ++count;
    }
}

Player * loser(Game &game)
{
    for (unsigned int index = 0; index < game.playerNumber; ++index)
    {
        if (game.players[index].score == 4) return &game.players[index];
    }
    return nullptr;
}

void show_score(Game &game)
{
    for (uint index = 0; index < game.playerNumber; ++index)
    {
        Player &currentPlayer = game.players[index];
        cout << currentPlayer.id << currentPlayer.type << " : " <<((float)currentPlayer.score)/4;
        if (index+1 != game.playerNumber) cout << "; ";
    }
    cout << endl;
    destroy(game.word); // Destroys/resets the word since the game is finished.
    init(&game.word);
}

void check_word(Game &game, Tree &dictionary, Player &currentPlayer, uint &playerTurn)
{
    if (search(dictionary, game.word) && strlen(game.word.value) > 2)
    {
        cout << "le mot " << get(game.word) << " existe, le joueur " << currentPlayer.id
             << currentPlayer.type << " prend un quart de singe" << endl;
        currentPlayer.score++;
        show_score(game);
    }
    else playerTurn = (playerTurn+1)%game.playerNumber;
}

void ask_word(Game &game, Tree &dictionary, uint &playerTurn)
{
    Player * currentPlayer = &game.players[playerTurn];
    char * newWord;

    cout << currentPlayer->id << currentPlayer->type << ", saisir le mot > ";

    if (is_human(*currentPlayer))
    {
        char playerWord[26];
        cin >> playerWord; toupper(playerWord);
        newWord = playerWord;
    }
    else
    {
        newWord = get(currentPlayer->word);
    }



    if (strstr(newWord, get(game.word)) != newWord)
    {
        cout << "le mot " << newWord << " ne commence pas par les lettres attendues, le joueur "
             << currentPlayer->id << currentPlayer->type << " prend un quart de singe" << endl;
    }
    else if (search(dictionary, newWord) && strlen(newWord) > 2)
    {
        playerTurn = (playerTurn+1)%game.playerNumber;
        currentPlayer = &game.players[playerTurn];
        cout << "le mot " << newWord << " existe, le joueur "
             << currentPlayer->id << currentPlayer->type << " prend un quart de singe" << endl;
    }
    else
    {
        cout << "le mot " << newWord << " n'existe pas, le joueur "
             << currentPlayer->id << currentPlayer->type << " prend un quart de singe" << endl;
    }
    currentPlayer->score++;
    show_score(game);
}

void new_game(Game &game, Tree &dictionary)
{
    uint playerTurn = 0;
    while (!loser(game))
    {
        Player &currentPlayer = game.players[playerTurn];
        cout << currentPlayer.id << currentPlayer.type << ", (" << game.word.value << ") > ";


        char newChar;
        if (is_human(currentPlayer))
        {
            cin >> newChar;
            cin.ignore(INT_MAX, '\n');
        }
        else
        {
            if (currentPlayer.word == nullptr || strstr(get(currentPlayer.word),
                       get(game.word)) != get(currentPlayer.word))
                get_new_word(currentPlayer, dictionary, game.word);

            if (currentPlayer.haveAWord)
                newChar = get_next_character(currentPlayer, game.word);
            else newChar = '?';

            cout << newChar;
        }

        if (newChar >= 'a' && newChar <= 'z') newChar = (char) toupper(newChar);

        switch (newChar)
        {
            case '?':
                if (playerTurn == 0) playerTurn = game.playerNumber-1;
                else playerTurn--;
                ask_word(game, dictionary, playerTurn);
                break;
            case '!':
                cout << "le joueur " << currentPlayer.id << currentPlayer.type
                     << " abandonne la manche et prend un quart de singe" << endl;
                currentPlayer.score++;
                show_score(game);
                break;
            default:
                if (!is_allocated(game.word))
                    set(game.word, "");
                append(game.word, newChar);
                check_word(game, dictionary, currentPlayer, playerTurn);
        }

    }
    cout << "La partie est finie" << endl;
}

void initialize(Game &game, Tree &dictionary, const char * szPlayers)
{
    assert (szPlayers != nullptr);
    init(&game.word);
    game.playerNumber = strlen(szPlayers);
    game.players = new Player[game.playerNumber];

    for (uint indPlayers = 0; indPlayers < game.playerNumber; ++indPlayers)
    {
        assert (szPlayers[indPlayers] == 'R' || szPlayers[indPlayers] == 'H' );
        initialize(game.players[indPlayers], szPlayers[indPlayers],
                   indPlayers+1, dictionary);
    }
}

void destroy(Game &game)
{
    destroy(game.word);
    game.playerNumber = 0;
    delete [] game.players;
}