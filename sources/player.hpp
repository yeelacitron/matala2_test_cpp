#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace ariel{
    class Player{
        private:
            std::string name;
            bool in_game;
            int nextCard;
            int points;
            int cardsInStack;
            int winRate;
        
        public:
            
            Player(std::string name_): name(name_),in_game(false),points(0),cardsInStack(26),winRate(0){}

            std::string getName() const{
                return this->name;
            }  
            bool getIn_game() const{
                return this->in_game;
            } 
            void setIn_game(bool bol){
                this->in_game = bol;
            }
            size_t getNextCard();
            void setNextCard(int num){
                this->nextCard = num;
            }
            int cardesTaken() const{
                return this->points;
            }
            void setPoints(int num){
                this->points = num;
            }
            int stacksize() const{
                return this->cardsInStack;
            }
            void setCardsInStack(int num){
                this->cardsInStack = num;
            }
            void setWinRate(int num){
                winRate = num;
            }
            int getWinRate(){
                return winRate;
            }


        
    };
}
