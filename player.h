#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include <vector>

class Player {
    private:
        std::vector<Card> deck; 
    public:
        std::vector<Card> get_deck(void) const;
        void add_to_deck(Card card);
        int get_sum(void) const;
        void print_deck(void) const;
        void clear_deck(void);
};

#endif