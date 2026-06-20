#include "player.h"
#include <iostream>
#include <vector>

std::vector<Card> Player::get_deck(void) const {
    /**
     * Get the deck of the player
     * @return: a vector of Card objects representing the player's deck
     */
    return this->deck;
}

void Player::add_to_deck(Card card) {
    /**
     * Add a card to the player's deck
     * @param card: the Card object representing a card to add to the player's deck
     */
    this->deck.push_back(card);
    if (get_sum() > 21) { 
        for (int i = 0; i < this->deck.size(); ++i) {
            if (this->deck[i].getValue() == 11) { // Aces can be 11 or 1, depending on deck sum
                this->deck[i].setValue(1);
                break;
            }   
        }
    }
}

int Player::get_sum(void) const {
    /**
     * Calculates the sum of the card values in the player's deck
     * @return: an integer number representing the sum
     */
    int sum = 0;
    for (int i = 0; i < this->deck.size(); ++i) {
        sum += deck[i].getValue();
    }
    return sum;
}

void Player::print_deck(void) const {
    /**
     * Prints out the player's card values in their deck
     */
    for (Card card : this->deck) {
        std::cout << card.getValue() << " ";
    }
    std::cout << std::endl;
}

void Player::clear_deck(void) {
    /**
     * Clears the player's deck (it will hold nothing)
     */
    this->deck.clear();
}