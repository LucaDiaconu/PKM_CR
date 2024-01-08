//
// Created by lucad on 08/01/2024.
//

#ifndef PKM_CR_TRAINERCARD_H
#define PKM_CR_TRAINERCARD_H


#include "Card.h"

class TrainerCard : public Card {
public:
    TrainerCard(string trainerEffect);
    void displayInfo() const override;
protected:
    string trainerEffect;
};


#endif //PKM_CR_TRAINERCARD_H
