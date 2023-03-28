#pragma once
#include "player.hpp"
#include "card.hpp"

namespace ariel{

    class Game {
        public:
            Player player_1;
            Player player_2;
            
            void printLastTurn();
            void playTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            

        // Game();   
        Game(Player p1,Player p2) : player_1(p1),player_2(p2){

        }   
    };
}