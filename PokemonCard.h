//
// Created by lucad on 08/01/2024.
//

#ifndef PKM_CR_POKEMONCARD_H
#define PKM_CR_POKEMONCARD_H

#include <vector>
#include "Card.h"

class PokemonCard : public Card{
public :
    PokemonCard(string cardNamed, string _pokemonType, string _familyName,
                int _evolutionLevel, int _maxHP, int firstAttackCost, string firstAttackDescription, int firstAttackDamage,
                int secondAttackCost, string secondAttackDescription, int secondAttackDamage);
    void displayInfo() const override;
    bool isAlive() const;
    bool countEnergyCards(int attackIndex, int energyCost) const;
    void recievesAttack(int damage);

    void setHP(int hp);
    int getMaxHP() const;

    vector<tuple<int, int, string, int>> attacks;
protected:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
};


#endif //PKM_CR_POKEMONCARD_H
