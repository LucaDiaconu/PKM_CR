//
// Created by lucad on 08/01/2024.
//

#ifndef PKM_CR_CARD_H
#define PKM_CR_CARD_H

#include <string>
using namespace std;


class Card {
public:
    Card(string);
    virtual void displayInfo() const = 0;
    string getName() const;

protected:
    string cardName;
};


#endif //PKM_CR_CARD_H
