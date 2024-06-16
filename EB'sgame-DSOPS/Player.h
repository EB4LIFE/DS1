#ifndef PLAYER_H
#define PLAYER_H

#include <queue>
#include <stack>
#include <vector>
#include "Card.h"

enum Operation {
    FILL_QUEUE,
    EMPTY_QUEUE,
    FILL_STACK,
    EMPTY_STACK
};

class Player {
public:
    std::queue<Card> playerQueue;
    std::stack<Card> playerStack;
    Operation operation;
    int penalty;

    void performAction(const Card &card);
    bool checkWin();
    void initializeForEmptyOperation(std::vector<Card> &deck);
    void displayProgress();
    void chooseOperation();
};

#endif // PLAYER_H
