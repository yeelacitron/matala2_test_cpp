#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#define TURNS 5
#define STACK_SIZE 52

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
            CHECK(p1.stacksize()==(STACK_SIZE/2));
            CHECK(p2.stacksize()==(STACK_SIZE/2));
    }
    SUBCASE("Throw exception in printWiner() when there is no winner at the beginning of the game"){
            CHECK_THROWS(game.printWiner());
    }
    SUBCASE("Shoudn't throw exception in print functions except for the function printWiner()"){
            CHECK_NOTHROW(game.printLastTurn());
            CHECK_NOTHROW(game.printLog());
            CHECK_NOTHROW(game.printStats());
    } 
}
TEST_CASE("Throw exception if both players are the same"){
    Player p1("bob");
    CHECK_THROWS_AS(Game game(p1,p1),invalid_argument);
}

TEST_CASE("The game is not over and five turns have been played"){
    Player p1("bob");
    Player p2("alice");
    Game game(p1,p2); 
    for (int i=0;i< TURNS;i++) {
        game.playTurn();
        if(p1.stacksize()==0){
            break;
        }
    }
    if(p1.stacksize() > 0){
        SUBCASE("Test that at least one of the players receives the right amount (a multiple of 2) of cards in cardesTaken()"){
                CHECK((p1.cardesTaken()>0 || p2.cardesTaken()>0));
                CHECK((p1.cardesTaken()%2==0 && p2.cardesTaken()%2==0));
                CHECK((p1.cardesTaken()+ p2.cardesTaken())<=(STACK_SIZE -2));
                CHECK((p1.cardesTaken()+ p2.cardesTaken())>=(TURNS*2));
        }
        SUBCASE("Test that at least five cards have been taken from the stacksize() of each player"){
                CHECK(p1.stacksize() <=(STACK_SIZE/2-TURNS));
                CHECK(p2.stacksize() <=(STACK_SIZE/2-TURNS));
        }
        SUBCASE("Throw exception in printWiner() when the game in not over"){
                CHECK_THROWS(game.printWiner());
        }  
    }
}

TEST_CASE("The game has been played and is over"){
    Player p1("bob");
    Player p2("alice");
    Game game(p1,p2); 
    game.playAll();
    SUBCASE("Test that there are no cards in stacksize()"){
            CHECK(p1.stacksize()==0);
            CHECK(p2.stacksize()==0);
    }
    SUBCASE("Test that at least one of the players has cardesTaken()"){
        CHECK((p1.cardesTaken()>0 || p2.cardesTaken()>0));
        CHECK((p1.cardesTaken()+p2.cardesTaken())== STACK_SIZE);

    }
    int points_p1 = p1.cardesTaken();
    int points_p2= p2.cardesTaken();
    SUBCASE("Test the trying to play a trun (using playTurn()) after the end of the game doesn't change the previous outcome"){
        game.playTurn();
        CHECK(p1.cardesTaken()== points_p1);
        CHECK(p2.cardesTaken()== points_p2);
    }
    SUBCASE("Test the trying to play a trun (using playAll()) after the end of the game doesn't change the previous outcome"){
        game.playAll();
        CHECK(p1.cardesTaken()== points_p1);
        CHECK(p2.cardesTaken()== points_p2);
    }
    SUBCASE("The game is over and shoudn't throw exceptions in the print functions"){
            CHECK_NOTHROW(game.printWiner());
            CHECK_NOTHROW(game.printLastTurn());
            CHECK_NOTHROW(game.printLog());
            CHECK_NOTHROW(game.printStats());
    }  
}

TEST_CASE("The same player tried to play in two different games"){
    Player p1("bob");
    Player p2("alice");
    Player p3("alex");
    Game game1(p1,p2); 
    
    SUBCASE("Throws exception if Player p1 tries to join the second game"){
            CHECK_THROWS_AS(Game game2(p1,p3),invalid_argument);
    }
    
    SUBCASE("Shouldn't throw exception when trying to play the first game"){
        CHECK_NOTHROW(game1.playTurn());
        CHECK_NOTHROW(game1.playAll());
    }
    Player p4("ari");
    SUBCASE("Shouldn't throw exception when player p3 tries to join a different game"){
        CHECK_NOTHROW(Game game3(p3,p4));
    }

}





