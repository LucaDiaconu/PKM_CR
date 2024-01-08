//
// Created by lucad on 08/01/2024.
//

#include "EnergyCard.h"

#include <utility>
#include <iostream>

EnergyCard::EnergyCard(string _energyType) :
        Card("Energy"), energyType(_energyType)
{
}

void EnergyCard::displayInfo() const {
    cout << "Card Name : " << this->cardName
         << ", Type : " << this->energyType << endl;
}

