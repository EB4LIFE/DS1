#include "Player.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Player::performAction(const Card &card) {
    if (card.suit == "Hearts") {
        if (operation == FILL_QUEUE) {
            playerQueue.push(card);
            std::cout << "Enqueued ";
        } else if (operation == EMPTY_QUEUE) {
            playerQueue.push(card);
            std::cout << "Penalty (Enqueue) ";
        } else if (operation == FILL_STACK) {
            playerStack.push(card);
            std::cout << "Pushed ";
        } else if (operation == EMPTY_STACK) {
            playerStack.push(card);
            std::cout << "Penalty (Push) ";
        }
    } else if (card.suit == "Diamonds") {
        if (operation == EMPTY_QUEUE) {
            if (!playerQueue.empty()) {
                std::cout << "Dequeued ";
                Game::displayCard(playerQueue.front());
                playerQueue.pop();
            } else {
                std::cout << "Queue is empty!";
            }
        } else if (operation == FILL_QUEUE) {
            penalty = -1;
            std::cout << "Penalty (Dequeue) ";
        }
    } else if (card.suit == "Clubs") {
        if (operation == FILL_QUEUE) {
            playerQueue.push(card);
            std::cout << "Enqueued ";
        } else if (operation == EMPTY_QUEUE) {
            playerQueue.push(card);
            std::cout << "Penalty (Enqueue) ";
        } else if (operation == FILL_STACK) {
            playerStack.push(card);
            std::cout << "Pushed ";
        } else if (operation == EMPTY_STACK) {
            playerStack.push(card);
            std::cout << "Penalty (Push) ";
        }
    } else if (card.suit == "Spades") {
        if (operation == EMPTY_STACK) {
            if (!playerStack.empty()) {
                std::cout << "Popped ";
                Game::displayCard(playerStack.top());
                playerStack.pop();
            } else {
                std::cout << "Stack is empty!";
            }
        } else if (operation == FILL_STACK) {
            penalty = -1;
            std::cout << "Penalty (Pop) ";
        }
    }
    std::cout << " - Drawn: ";
    Game::displayCard(card);
    std::cout << std::endl;
}

bool Player::checkWin() {
    if (operation == FILL_QUEUE && playerQueue.size() == 8) return true;
    if (operation == EMPTY_QUEUE && playerQueue.empty()) return true;
    if (operation == FILL_STACK && playerStack.size() == 8) return true;
    if (operation == EMPTY_STACK && playerStack.empty()) return true;
    return false;
}

void Player::initializeForEmptyOperation(std::vector<Card> &deck) {
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
        std::cout << "Queue size: " << playerQueue.size() << " / 8" << std::endl;
    } else if (operation == EMPTY_QUEUE) {
        std::cout << "Queue remaining: " << playerQueue.size() << std::endl;
    } else if (operation == FILL_STACK) {
        std::cout << "Stack size: " << playerStack.size() << " / 8" << std::endl;
    } else if (operation == EMPTY_STACK) {
        std::cout << "Stack remaining: " << playerStack.size() << std::endl;
    }
}

void Player::chooseOperation() {
    srand(static_cast<unsigned int>(time(0)));
    int randomChoice = rand() % 4;
    operation = static_cast<Operation>(randomChoice);
}
