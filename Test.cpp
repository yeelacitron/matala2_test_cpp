#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("The start of the game when no turns have been played"){
    Player p1("bob");
    Player p2("alice");
    Game game(p1,p2); 
    SUBCASE("Testing cardesTaken()"){
        CHECK(p1.cardesTaken()==0);
        CHECK(p2.cardesTaken()==0);
    }
    SUBCASE("Testing stacksize()"){
            CHECK(p1.stacksize()==26);
            CHECK(p2.stacksize()==26);
    }
    SUBCASE("Throw exception in printWiner() when there is no winner at the start"){
            CHECK_THROWS(game.printWiner());
    }
}
TEST_CASE("Throw exception if the game has the same player"){
    Player p1("bob");
    CHECK_THROWS_AS(Game game(p1,p1),invalid_argument);
}

TEST_CASE("The game is not over and five turns have been played"){
    Player p1("bob");
    Player p2("alice");
    Game game(p1,p2); 
    for (int i=0;i<5;i++) {
        game.playTurn();
        if(p1.stacksize()==0){
            break;
        }
    }
    REQUIRE(p1.stacksize() >0);
    SUBCASE("Test that at leasts one of the players recieves cards and the right amount (a multiple of 2) in cardesTaken()"){
            CHECK((p1.cardesTaken()>0 || p2.cardesTaken()>0));
            CHECK((p1.cardesTaken()%2==0 && p2.cardesTaken()%2==0));
            CHECK((p1.cardesTaken()+ p2.cardesTaken())<=50);
            CHECK((p1.cardesTaken()+ p2.cardesTaken())>=10);
    }
    SUBCASE("Test that at least five card have been taken from the stacksize() of each player"){
            CHECK(p1.stacksize() <=21);
            CHECK(p2.stacksize() <=21);
    }
    SUBCASE("Throw exption in printWiner() when there no winner because the game in not over"){
            CHECK_THROWS(game.printWiner());
    }  
}

TEST_CASE("The game have been play and is over"){
    Player p1("bob");
    Player p2("alice");
    Game game(p1,p2); 
    game.playAll();
    SUBCASE("Test that there no cards in stacksize()"){
            CHECK(p1.stacksize()==0);
            CHECK(p2.stacksize()==0);
    }
    SUBCASE("Test that at least one of the player has cardesTaken()"){
        CHECK((p1.cardesTaken()>0 || p1.cardesTaken()>0));
    }
    SUBCASE("Throw exeption when trying to play turn after the end of the game"){
        CHECK_THROWS(game.playTurn());
        CHECK_THROWS(game.playAll());
    }
    SUBCASE("The game is over and shoudn't throw exepiton in print functions"){
            CHECK_NOTHROW(game.printWiner());
            CHECK_NOTHROW(game.printLastTurn());
            CHECK_NOTHROW(game.printLog());
            CHECK_NOTHROW(game.printStats());
    }  
}

TEST_CASE("The same player try to enter two differnt game"){
    Player p1("bob");
    Player p2("alice");
    Player p3("alex");
    Game game1(p1,p2); 
    
    SUBCASE("Throws exeption when trying to put Player in the second game"){
            CHECK_THROWS_AS(Game game2(p1,p3),exception);
    }
    
    SUBCASE("Shouldn't throw exeption when trying to play firstgame"){
        CHECK_NOTHROW(game1.playTurn());
    }

}





