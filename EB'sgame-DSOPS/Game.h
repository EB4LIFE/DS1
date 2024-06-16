#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Card.h"
#include "Player.h"

using namespace std;

class Game {
public:
    vector<Card> deck;
    vector<Card> discardPile;
    Player user;
    Player computer;

    Game();

    void createDeck();
    void shuffleDeck();
    void reshuffleDeck();
    static void displayCard(const Card &card);
    static void printOperationChoice(const Player &player);
    void play();
};

#endif // GAME_H

