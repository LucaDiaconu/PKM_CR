//
// Created by lucad on 08/01/2024.
//

#ifndef PKM_CR_PLAYER_H
#define PKM_CR_PLAYER_H

#include "Card.h"
#include "PokemonCard.h"
#include "TrainerCard.h"
#include <string>
#include <vector>
using namespace std;

class Player {

public:
    Player(string playerName);
    void addCardToBench(Card* card);
    void displayBench();
    void displayAction();
    void activatePokemonCard(int index);
    void attachEnergyCard(int benchIndex, int energyIndex);
    void removeEnergyCard(int benchIndex, int energyIndex);
    void attack(int benchIndex, int attackIndex, Player& enemy, int enemyBenchIndex);
    void useTrainer(int benchIndex);
    void applyTrainerEffect(TrainerCard *trainerCard);

protected:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;


};


#endif //PKM_CR_PLAYER_H
