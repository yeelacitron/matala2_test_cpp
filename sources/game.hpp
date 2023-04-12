#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "player.hpp"
#include "card.hpp"
#include <algorithm>
#include <random>

namespace ariel{
    static const std::vector<std::string> cardsToNumbers {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    class Game {
        private:
            Player & player_1;
            Player & player_2;
            std::vector<Card> stack;
            std::vector<std::string> log;
            int draw_rate;
            int rounds;
        public:
            void printLastTurn();
            void playTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            Game(Player & ply1,Player & ply2);
            void setLastlog(std::string  const & add){
                log.push_back(add);
            }
            Card getCardPly1() {
                Card rev = stack[player_1.getNextCard()];
                return  rev;
            }
            Card getCardPly2() {
                Card rev = stack.at(player_2.getNextCard());
                return rev;
            }
            void setDrawRate(int num){
                draw_rate = num;
            }
            int getDrawRate() const{
                return draw_rate;
            }
            void setRounds(int num){
                rounds= num;
            }
            int getRounds() const{
                return rounds;
            }
            
    };
}