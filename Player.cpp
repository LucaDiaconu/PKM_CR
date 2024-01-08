//
// Created by lucad on 08/01/2024.
//

#include <iostream>
#include "Player.h"
#include "EnergyCard.h"
#include "PokemonCard.h"
#include "Card.h"
#include "TrainerCard.h"

Player::Player(string _playerName):
playerName(_playerName)
{
}

void Player::addCardToBench(Card *card)
{
    benchCards.push_back(card);
}

void Player::displayBench()
{
    cout << "Bench cards for Player " << this->playerName << " : ";
    for (int i = 0; i < benchCards.size(); i++) {
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction()
{
    cout << "Action cards for Player " << this->playerName << " : ";
    for (int i = 0; i < actionCards.size(); i++) {
        actionCards[i]->displayInfo();
    }
}

void Player::activatePokemonCard(int index) {
    cout << this->playerName << " is activating a Pokemon Card : " << benchCards[index]->getName() << endl;
    actionCards.push_back((PokemonCard*)benchCards[index]);
    benchCards.erase(benchCards.begin() + index);
}


void Player::attachEnergyCard(int benchIndex, int energyIndex)
{
    if (benchIndex < actionCards.size() && energyIndex < benchCards.size()) {
        auto* pokemonCard = dynamic_cast<PokemonCard*>(actionCards[benchIndex]);
        auto* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);

        if (pokemonCard && energyCard) {
            get<1>(pokemonCard->attacks[0]) += 1;
            get<1>(pokemonCard->attacks[1]) += 1;

            cout << this->playerName << " is attaching an Energy Card of type " << energyCard->energyType
                 << " to the Pokemon " << pokemonCard->getName() << endl;

            benchCards.erase(benchCards.begin() + energyIndex);
        }
    }
}

void Player::removeEnergyCard(int benchIndex, int energyCost) {
    if (benchIndex < actionCards.size() && energyCost > 0) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(actionCards[benchIndex]);

        if (pokemonCard) {
            for(int i=0; i<pokemonCard->attacks.size();i++) {
                // Assuming that the energy card is always attached to the first attack slot
                int energyStorage = std::get<1>(pokemonCard->attacks[i]);

                // Ensure there are enough energy cards to remove
                if (energyStorage >= energyCost) {
                    // Remove the specified number of energy cards
                    std::get<1>(pokemonCard->attacks[i]) -= energyCost;

                }
            }
        }
    }
}


void Player::attack(int benchIndex, int attackIndex, Player &enemy, int enemyBenchIndex) {
    if (benchIndex < actionCards.size() && attackIndex < actionCards[benchIndex]->attacks.size()) {
        PokemonCard* attackingPokemon = dynamic_cast<PokemonCard*>(actionCards[benchIndex]);
        auto* enemyPokemon = dynamic_cast<PokemonCard*>(enemy.actionCards[enemyBenchIndex]);


        if (attackingPokemon) {

            int energyCost = std::get<0>(attackingPokemon->attacks[attackIndex]);

            if (attackingPokemon->countEnergyCards(attackIndex, energyCost)) {

                std::get<1>(attackingPokemon->attacks[attackIndex]) -= 1;

                int damage = std::get<3>(attackingPokemon->attacks[attackIndex]);
                enemyPokemon->recievesAttack(damage);

                cout << playerName << " attacking " << enemy.playerName << "'s Pokemon "
                     << enemyPokemon->getName() << " with the Pokemon "
                     << attackingPokemon->getName() << " with its attack : "
                     << get<2>(attackingPokemon->attacks[attackIndex]) << endl;

                cout << "Reducing " << damage << " from " << enemy.playerName << "'s Pokemon's HP" << endl;

                if (enemyPokemon->isAlive()) {
                    cout << "Pokemon " << enemyPokemon->getName() << " is still alive" << endl;
                } else {
                    cout << "Pokemon " << enemyPokemon->getName() << " fainted" << endl;
                }

                // Remove the energy cards used for the attack
                removeEnergyCard(attackIndex, energyCost);
            }
        }
    }
}


void Player::useTrainer(int benchIndex) {
    if (benchIndex < actionCards.size()) {
        auto* trainerCard = dynamic_cast<TrainerCard*>(actionCards[benchIndex]);

        if (trainerCard) {
            cout << playerName << " is using the Trainer Card to \"" << trainerCard->getEffect() << "\"" << endl;
            applyTrainerEffect(trainerCard);
            actionCards.erase(actionCards.begin() + benchIndex);
        }
    }
}

void Player::applyTrainerEffect(TrainerCard* trainerCard) {
    if (trainerCard->getEffect() == "heal all your action pokemon") {
        for (Card* card : actionCards) {
            if (auto* pokemonCard = dynamic_cast<PokemonCard*>(card)) {
                pokemonCard->setHP(pokemonCard->getMaxHP());
            }
        }
    }

    // Add more conditions to handle other Trainer Card effects as needed.
}







