#include <iostream>
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "Card.h"

int main() {
    PokemonCard card1 = *new PokemonCard(" Pikachu ", " Electric ", " Pikachu ", 2 , 100 , 2 , "thunder bolt", 20 , 3 , "thunder storm", 30);
    EnergyCard card2 = *new EnergyCard("Water");
    card1.displayInfo();
    card2.displayInfo();

    return 0;
}
