#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

struct Card {
    string suit;
    int value; // 2 to 14 (11=Jack, 12=Queen, 13=King, 14=Ace)
};

#endif // CARD_H
