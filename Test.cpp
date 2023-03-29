#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;
using namespace doctest;

//i used this url for better understanding of doctest : https://github.com/doctest/doctest/blob/master/doc/markdown/assertions.md

TEST_CASE("start of the game")
{
    // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   //create a new gmae with the tow players
   Game game(p1, p2);

   //check if the amount of cards for each player is 26
   CHECK(p1.stacksize() == 26);
   CHECK(p1.cardesTaken() == 0);
   CHECK(p2.stacksize() == 26);
   CHECK(p2.cardesTaken() == 0);

   CHECK_NOTHROW(game.printLog());
   CHECK_NOTHROW(game.printStats());
}

TEST_CASE("middle of the game")
{
   // Create two players with their names 
    Player p1("Alice");
    Player p2("Bob");

    //create a new game
    Game game(p1,p2); 

    //check that no exception is thrown for the first turn
    CHECK_NOTHROW(game.playTurn());

    //checks that the amount of cards for both players got smaller
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);

    //check that only one player has won
    CHECK((p1.cardesTaken() == 0 || p2.cardesTaken() == 0));

    //play 5 turns
    for (int i=0;i<5;i++) 
    {
        game.playTurn();
    }

    //checks that the amount of cards for both players got smaller
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
    CHECK(p1.cardesTaken() > 0);
    CHECK(p2.cardesTaken() > 0);

    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("end of the game")
{
    // Create two players with their names 
    Player p1("Alice");
    Player p2("Bob");

    //create a new game
    Game game(p1,p2); 

    CHECK_NOTHROW(game.playAll());

    //check that the players really played all cards
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    
   
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}