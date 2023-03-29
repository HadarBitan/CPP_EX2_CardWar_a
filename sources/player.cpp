#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    Player::Player(){}
    
    Player::Player(string name)
    {
        this->name = name;
    }

    int Player::stacksize() {return 0;}

    int Player::cardesTaken() {return 0;}

    Card * Player::drawCard() {return NULL;}
}