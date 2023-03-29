#ifndef PLAYER_HPP
#define PLAYER_HPP

#pragma once

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
    private:
        string name;
        int cardsLeft;

    public:
        Player();
        Player(string name);

        int stacksize();
        int cardesTaken();
        Card *drawCard();
    };
}

#endif