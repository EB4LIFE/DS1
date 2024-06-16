#include "OPchange.h"

OPchange::OPchange(Player &player)
    : player(player), penaltyApplied(false) {}

void OPchange::requestOperationChange(Operation newOperation) {
    if (canChangeOperation()) {
        player.operation = newOperation;
        applyPenalty();
    }
}

bool OPchange::canChangeOperation() const {
    return !penaltyApplied;
}

void OPchange::applyPenalty() {
    penaltyApplied = true;
    // Implement penalty logic here (e.g., skip next turn)
    // Example: player.skipNextTurn();
}

bool OPchange::hasPenalty() const {
    return penaltyApplied;
}
