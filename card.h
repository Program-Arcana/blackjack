#ifndef CARD_H
#define CARD_H

class Card {
    private:
        int value;
    public: 
        Card(void);
        Card(int val);
        int getValue(void) const;
        void setValue(int val);
};

#endif