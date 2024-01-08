//
// Created by lucad on 08/01/2024.
//

#ifndef PKM_CR_ENERGYCARD_H
#define PKM_CR_ENERGYCARD_H


#include "Card.h"

class EnergyCard: public Card {
public:
    EnergyCard(string energyType);
    void displayInfo() const override;

    string energyType;

};


#endif //PKM_CR_ENERGYCARD_H
