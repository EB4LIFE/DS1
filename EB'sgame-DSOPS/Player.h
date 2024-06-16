#ifndef PLAYER_H
#define PLAYER_H

#include <queue>
#include <stack>
#include <vector>
#include "Card.h"

using namespace std;

enum Operation {
    FILL_QUEUE,
    EMPTY_QUEUE,
    FILL_STACK,
    EMPTY_STACK
};

class Player {
public:
    queue<Card> playerQueue;
    stack<Card> playerStack;
    Operation operation;
    int penalty;

    void performAction(const Card &card);
    bool checkWin();
    void initializeForEmptyOperation(vector<Card> &deck);
    void displayProgress();
    void chooseOperation();
};

#endif // PLAYER_H
