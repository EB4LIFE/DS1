#ifndef OPCHANGE_H
#define OPCHANGE_H

#include "Player.h"

class OPchange {
public:
    OPchange(Player &player);

    void requestOperationChange(Operation newOperation);
    bool canChangeOperation() const;
    void applyPenalty();
    bool hasPenalty() const;

private:
    Player &player;
    bool penaltyApplied;
};

#endif // OPCHANGE_H
