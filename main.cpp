#include <algorithm>
#include <iostream>
#include <random>
#include "player.h"

void get_card(Player& p) {
    /**
     * Give a random card to a player, adding it to their deck
     * @param p: the player to give the card to
     */
    std::random_device rd; // RNG
    std::mt19937 mt(rd()); // Mersenne Twister 19937 pseudo-generator
    std::uniform_int_distribution<int> index(0, 12); // numbers between 0 and 12 will have equal chance of being picked
    int card_vals[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    Card card(card_vals[index(mt)]); // Card is assigned random value from card_vals based on random index picked
    p.add_to_deck(card);
}

void initial_deal(Player& p1, Player& p2) {
    /**
     * Deal out the first two cards to each player
     * @param p: the player to deal the cards to
     */
    for (int i = 0; i < 2; ++i) {
        get_card(p1);
        get_card(p2);
    }
}

std::string get_upper(std::string str) {
    /**
     * Get a string's uppercase form
     * @param str: the string to get the uppercase form of
     * @return: the uppercase form of the given string
     */
    std::string upper_str = str;
    for (int i = 0; i < str.size(); ++i) {
        upper_str[i] = std::toupper(str[i]);
    }
    return upper_str;
}

bool player_wins(Player& p, Player& d) {
    /**
     * Determines if the player won or not
     * @param p: Player object representing the player (you)
     * @param d: Player object representing the dealer
     * @return: true if the player won, false otherwise
     */
    return ((p.get_sum() <= 21) && ((p.get_sum() > d.get_sum()) || (d.get_sum() > 21)));
}

int main(void) {
    // Initialization and setup
    Player player, dealer;
    std::string choice;
    int bet_amount = 0; 
    int money_left = 1000;
    int amount_earned = 0;
    // Main Game Loop
    while (money_left > 0) {
        // Get bet amount
        std::cout << "---------------------\n♠️ ♥️  BLACKJACK ♣️ ♦️ " << std::endl;
        std::cout << "You currently have: $" << money_left << std::endl;
        std::cout << "Enter bet amount: $";
        std::cin >> bet_amount;
        if ((bet_amount <= money_left) && (bet_amount > 0)) { // Start game if bet sufficient/valid
            money_left -= bet_amount; 
            initial_deal(player, dealer);
            // Player's Turn
            while (player.get_sum() < 21) {
                // Print player info
                std::cout << "---------------------\nYour Deck: ";
                player.print_deck();
                std::cout << "Your Sum: " << player.get_sum() << std::endl;
                // Present game choices and react accordingly
                std::cout << "Hit or Stand? (H/S): ";
                std::cin >> choice;
                if (choice.size() == 1) {
                    if (get_upper(choice) == "H") { // Hit (get a card)
                        get_card((player));
                    } else if (get_upper(choice) == "S") { // Stand (stop getting cards)
                        break;
                    } else {
                        std::cout << "---------------------\n⚠️ Error: invalid choice." << std::endl;
                    }
                } else {
                    std::cout << "---------------------\n⚠️ Error: input must be a char." << std::endl;
                }
            }
            // Dealer's Turn
            while (dealer.get_sum() < 16) {
                get_card(dealer);
            }
            // Game Results
            if (player_wins(player, dealer)) {
                std::cout << "---------------------\nYOU WIN!" << std::endl;
                money_left += 2 * bet_amount;
                amount_earned += bet_amount;
            } else {
                std::cout << "---------------------\nYOU LOSE (DEALER WINS)..." << std::endl;
            }
            std::cout << "Your Deck: ";
            player.print_deck();
            std::cout << "Your Final Score: " << player.get_sum() << std::endl;
            std::cout << "Dealer Deck: ";
            dealer.print_deck();
            std::cout << "Dealer Final Score: " << dealer.get_sum() << std::endl;
            // Reset decks
            player.clear_deck();
            dealer.clear_deck();
        } else {
            std::cout << "---------------------\n⚠️ Error: invalid bet." << std::endl;
        }
        // Prevent infinite loop when invalid type is entered
        std::cin.clear(); // Reset error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears everything in input buffer
    }
    // Final Earnings/Losses
    std::cout << "---------------------\n📊 FINAL RESULTS" << std::endl;
    std::cout << "Total Earnings: $" << amount_earned << std::endl;
    std::cout << "---------------------" << std::endl;
    return 0;
}