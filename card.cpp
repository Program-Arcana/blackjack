#include "card.h"

Card::Card(void) { // Default Constructor
    this->value = 0;
}

Card::Card(int val) { // Parameterized Constructor
    this->value = val;
}

int Card::getValue(void) const {
    /**
     * Gets the value on the card
     * @return: an integer value that the Card object holds
     */
    return this->value;
}

void Card::setValue(int val) {
    /**
     * Sets the value of the card to a given value
     * @param val: the value to set the card to
     */
    this->value = val;
}