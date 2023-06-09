#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player p1;
        Player p2;

    public:
        Game(Player first_player, Player second_player);
        void generatePack();
        void divideCards();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}

#endif
