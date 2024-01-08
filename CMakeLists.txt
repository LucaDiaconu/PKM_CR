cmake_minimum_required(VERSION 3.26)
project(PKM_CR)

set(CMAKE_CXX_STANDARD 17)

add_executable(PKM_CR main.cpp
        Card.cpp
        Card.h
        PokemonCard.cpp
        PokemonCard.h
        EnergyCard.cpp
        EnergyCard.h
        TrainerCard.cpp
        TrainerCard.h
        Player.cpp
        Player.h)
