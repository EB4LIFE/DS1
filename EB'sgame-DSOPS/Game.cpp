#include "Game.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

Game::Game() {
    createDeck();
    shuffleDeck();
    computer.chooseOperation();
}

void Game::createDeck() {
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for (const string &suit : suits) {
        for (int value = 2; value <= 14; ++value) {
            deck.push_back({suit, value});
        }
    }
}

void Game::shuffleDeck() {
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(deck.begin(), deck.end());
}

void Game::reshuffleDeck() {
    if (deck.empty()) {
        deck = discardPile;
        discardPile.clear();
        shuffleDeck();
        cout << "Deck reshuffled!\n";
    }
}

void Game::displayCard(const Card &card) {
    string value;
    if (card.value <= 10) value = to_string(card.value);
    else if (card.value == 11) value = "Jack";
    else if (card.value == 12) value = "Queen";
    else if (card.value == 13) value = "King";
    else value = "Ace";

    cout << value << " of " << card.suit;
}

void Game::printOperationChoice(const Player &player) {
    string operation;
    switch (player.operation) {
        case FILL_QUEUE:
            operation = "Fill Queue";
            break;
        case EMPTY_QUEUE:
            operation = "Empty Queue";
            break;
        case FILL_STACK:
            operation = "Fill Stack";
            break;
        case EMPTY_STACK:
            operation = "Empty Stack";
            break;
    }
    cout << operation << endl;
}

void Game::play() {
    shuffleDeck();
    int userChoice;
    cout << "Choose your operation:\n";
    cout << "0: Fill Queue\n1: Empty Queue\n2: Fill Stack\n3: Empty Stack\n";
    cin >> userChoice;
    user.operation = static_cast<Operation>(userChoice);

    cout << "User's choice: ";
    printOperationChoice(user);
    cout << "Computer's choice: ";
    printOperationChoice(computer);

    user.initializeForEmptyOperation(deck);
    computer.initializeForEmptyOperation(deck);

    cout << "Game start! Press Enter to draw a card.\n";

    while (true) {
        cout << "User's turn:\n";
        cin.ignore();
        cin.get();
        reshuffleDeck();
        Card drawnCard = deck.back();
        deck.pop_back();
        user.performAction(drawnCard);
        discardPile.push_back(drawnCard);
        if (user.checkWin()) {
            cout << "User wins the round!\n";
            break;
        }
        user.displayProgress();

        cout << "Computer's turn:\n";
        cin.get();
        reshuffleDeck();
        drawnCard = deck.back();
        deck.pop_back();
        computer.performAction(drawnCard);
        discardPile.push_back(drawnCard);
        if (computer.checkWin()) {
            cout << "Computer wins the round!\n";
            break;
        }
        computer.displayProgress();
    }
}
