#include "Player.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Player::performAction(const Card &card) {
    if (card.suit == "Hearts") {
        if (operation == FILL_QUEUE) {
            playerQueue.push(card);
            cout << "Enqueued ";
        } else if (operation == EMPTY_QUEUE) {
            playerQueue.push(card);
            cout << "Penalty (Enqueue) ";
        } else if (operation == FILL_STACK) {
            playerStack.push(card);
            cout << "Pushed ";
        } else if (operation == EMPTY_STACK) {
            playerStack.push(card);
            cout << "Penalty (Push) ";
        }
    } else if (card.suit == "Diamonds") {
        if (operation == EMPTY_QUEUE) {
            if (!playerQueue.empty()) {
                cout << "Dequeued ";
                Game::displayCard(playerQueue.front());
                playerQueue.pop();
            } else {
                cout << "Queue is empty!";
            }
        } else if (operation == FILL_QUEUE) {
            penalty = -1;
            cout << "Penalty (Dequeue) ";
        }
    } else if (card.suit == "Clubs") {
        if (operation == FILL_QUEUE) {
            playerQueue.push(card);
            cout << "Enqueued ";
        } else if (operation == EMPTY_QUEUE) {
            playerQueue.push(card);
            cout << "Penalty (Enqueue) ";
        } else if (operation == FILL_STACK) {
            playerStack.push(card);
            cout << "Pushed ";
        } else if (operation == EMPTY_STACK) {
            playerStack.push(card);
            cout << "Penalty (Push) ";
        }
    } else if (card.suit == "Spades") {
        if (operation == EMPTY_STACK) {
            if (!playerStack.empty()) {
                cout << "Popped ";
                Game::displayCard(playerStack.top());
                playerStack.pop();
            } else {
                cout << "Stack is empty!";
            }
        } else if (operation == FILL_STACK) {
            penalty = -1;
            cout << "Penalty (Pop) ";
        }
    }
    cout << " - Drawn: ";
    Game::displayCard(card);
    cout << endl;
}

bool Player::checkWin() {
    if (operation == FILL_QUEUE && playerQueue.size() == 8) return true;
    if (operation == EMPTY_QUEUE && playerQueue.empty()) return true;
    if (operation == FILL_STACK && playerStack.size() == 8) return true;
    if (operation == EMPTY_STACK && playerStack.empty()) return true;
    return false;
}

void Player::initializeForEmptyOperation(vector<Card> &deck) {
    if (operation == EMPTY_QUEUE) {
        for (int i = 0; i < 8 && !deck.empty(); ++i) {
            playerQueue.push(deck.back());
            deck.pop_back();
        }
    } else if (operation == EMPTY_STACK) {
        for (int i = 0; i < 8 && !deck.empty(); ++i) {
            playerStack.push(deck.back());
            deck.pop_back();
        }
    }
}

void Player::displayProgress() {
    if (operation == FILL_QUEUE) {
        cout << "Queue size: " << playerQueue.size() << " / 8" << endl;
    } else if (operation == EMPTY_QUEUE) {
        cout << "Queue remaining: " << playerQueue.size() << endl;
    } else if (operation == FILL_STACK) {
        cout << "Stack size: " << playerStack.size() << " / 8" << endl;
    } else if (operation == EMPTY_STACK) {
        cout << "Stack remaining: " << playerStack.size() << endl;
    }
}

void Player::chooseOperation() {
    srand(static_cast<unsigned int>(time(0)));
    int randomChoice = rand() % 4;
    operation = static_cast<Operation>(randomChoice);
}
