#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Card.h"
#include "Player.h"
#include "OPchange.h" // Include OPchange header

using namespace std;

class Game {
public:
    vector<Card> deck;
    vector<Card> discardPile;
    Player user;
    Player computer;
    OPchange operationChangeManagerUser;     // OPchange instance for user
    OPchange operationChangeManagerComputer; // OPchange instance for computer

    Game();

    void createDeck();
    void shuffleDeck();
    void reshuffleDeck();
    static void displayCard(const Card &card);
    static void printOperationChoice(const Player &player);
    void play();
    bool playerRequestsOperationChange(Player &player);
};

#endif // GAME_H


