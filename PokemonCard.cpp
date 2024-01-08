//
// Created by lucad on 08/01/2024.
//
#include <iostream>
#include <utility>
#include "PokemonCard.h"

PokemonCard::PokemonCard(string cardName, string _pokemonType, string _familyName,
                         int _evolutionLevel, int _maxHP, int _firstAttackCost, string _firstAttackDescription, int _firstAttackDamage,
                         int _secondAttackCost, string _secondAttackDescription, int _secondAttackDamage) :
        Card(cardName), pokemonType(_pokemonType), familyName(_familyName),
        evolutionLevel(_evolutionLevel), maxHP(_maxHP), hp(_maxHP)
{
    attacks.emplace_back(_firstAttackCost, 0, _firstAttackDescription, _firstAttackDamage);
    attacks.emplace_back(_secondAttackCost, 0, _secondAttackDescription, _secondAttackDamage);
}

void PokemonCard::displayInfo() const
{
    cout << "Pokemon Card - Name : " << this->cardName
         << ", Type : " << this->pokemonType
         << ", Evolution Level : " << this->evolutionLevel
         << " of the family \"" << this->familyName
         << ", HP : " << this->hp << "\"" << endl;
    cout << "Attacks: " << endl;
    for (int i = 0; i < attacks.size(); i++) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl;
        cout << "Attack current energy storage: " << get<1>(attacks[i]) << endl;
        cout << "Attack description: " << get<2>(attacks[i]) << endl;
        cout << "Attack damage: " << get<3>(attacks[i]) << endl;
    }

}

bool PokemonCard::isAlive() const 
{
    return (this->hp > 0) ? true : false;
}

void PokemonCard::recievesAttack(int _damage) {
    (this->hp > _damage) ? this->hp -= _damage : this->hp = 0;
}

bool PokemonCard::countEnergyCards(int _attackIndex, int _energyCost) const {
    return (get<1>(attacks[_attackIndex]) >= _energyCost);
}

void PokemonCard::setHP(int _hp) {
    this->hp = _hp;
}

int PokemonCard::getMaxHP() const {
    return this->maxHP;
}
