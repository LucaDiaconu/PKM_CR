//
// Created by lucad on 08/01/2024.
//

#include <iostream>
#include "TrainerCard.h"


TrainerCard::TrainerCard(string _trainerEffect) :
        Card("Energy"), trainerEffect(_trainerEffect)
{
}

void TrainerCard::displayInfo() const {
    cout << "Card Name : " << this->cardName
         << ", Effect : " << this->trainerEffect << endl;
}

