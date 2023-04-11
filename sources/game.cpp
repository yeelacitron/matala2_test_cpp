#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <ctime>
#include <cstdlib>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;
using namespace ariel;


void Game::printLastTurn(){
    if(&player_1 == &player_2){
        cout << "same player in the game" << endl;
        throw exception();
    }
    cout << log.at(log.size()-1)<<endl;
}
void Game::playTurn(){
    if(&player_1 == &player_2){
        cout << "same player in the game" << endl;
        throw exception();
    }
    if(player_1.stacksize() >0){
        string add ="";
        bool tie = true;
        int rounds =0;
        int draws=0;
        while(tie && player_1.stacksize() >0){
            Card cardP1 = getCardPly1();
            Card cardP2 = getCardPly2();
            rounds++;
            add = add + player_1.getName() + " played "+cardsToNumbers.at(cardP1.getValue()-1)+" "+cardP1.getShape() + " " + \
                player_2.getName() + " played "+cardsToNumbers.at(cardP2.getValue()-1) +" "+ cardP2.getShape();
            if(cardP1.getValue() != 1 && cardP2.getValue()!= 1 ){
                if(cardP1.getValue()< cardP2.getValue()){ //player 2 wins
                    add = add +". "+ player_2.getName()+ " wins.";
                    player_2.setPoints(player_2.cardesTaken()+2*(rounds));
                    player_2.setWinRate(player_2.getWinRate()+1);
                    tie = false;
                }
                else if (cardP1.getValue()> cardP2.getValue()){//player 1 wins
                    add = add +". "+ player_1.getName()+ " wins.";
                    player_1.setPoints(player_1.cardesTaken()+2*(rounds));
                    player_1.setWinRate(player_1.getWinRate()+1);
                    tie = false;
                }
                else{ //draw
                    add = add + ". draw. ";
                    if(player_1.stacksize() >0){
                        getCardPly1();
                        getCardPly2();
                        rounds++;
                        draws++;
                    }
                }
            }
            else{
                if(cardP1.getValue() == 1 && cardP2.getValue() == 1 ){//draw
                    add = add + ". draw. ";
                    if(player_1.stacksize() >0){
                        getCardPly1();
                        getCardPly2();
                        rounds++;
                        draws++;
                    }
                }
                else if ((cardP1.getValue() == 1 && cardP2.getValue() != 2)||(cardP1.getValue() == 2 && cardP2.getValue() == 1)){ //player 1 wins
                    add = add +". "+ player_1.getName()+ " wins.";
                    player_1.setPoints(player_1.cardesTaken()+2*(rounds));
                    player_1.setWinRate(player_1.getWinRate()+1);
                    tie = false;
                }
                else if((cardP2.getValue() == 1 && cardP1.getValue() != 2)||(cardP2.getValue() == 2 && cardP1.getValue() == 1)){ //player 2 wins
                    add = add +". "+ player_2.getName()+ " wins.";
                    player_2.setPoints(player_2.cardesTaken()+2*(rounds));
                    player_2.setWinRate(player_2.getWinRate()+1);
                    tie = false;
                }
            }    
        }
        setLastlog(add);
        setDrawRate(getDrawRate()+draws);
        if(tie){
            player_1.setPoints(player_1.cardesTaken()+rounds);
            player_2.setPoints(player_2.cardesTaken()+rounds);
        }

    }
    else{
        cout << "The game is over can't play turn" << endl;
        throw exception();       
    } 
}
void Game::playAll(){
    if(&player_1 == &player_2){
        cout << "same player in the game" << endl;
        throw exception();
    }
    while(player_1.stacksize()>0){
        playTurn();
    }
    
}
void Game::printWiner(){
    if(&player_1 == &player_2){
        cout << "same player in the game" << endl;
        throw exception();
    }
    if(player_1.stacksize()>0){
        cout<<"the game is not over, no winners yet"<<endl;
        return;
    }
    if(player_1.cardesTaken()>player_2.cardesTaken()){
        cout<< player_1.getName()<<endl;
    }
    else if(player_1.cardesTaken()<player_2.cardesTaken()){
        cout<< player_2.getName()<<endl;
    }
    else{
        cout << "draw"<<endl;
    }
    
}
void Game::printLog(){
    if(&player_1 == &player_2){
        cout << "same player in the game" << endl;
        throw exception();
    }
    for(size_t i =0;i<log.size();i++){
        cout << log.at(i)<<endl;
    }
    
}
void Game::printStats(){
    if(&player_1 == &player_2){
        cout << "same player in the game" << endl;
        throw exception();
    }
    cout<< player_1.getName()+": "<<endl;
    cout<<"cards won: "+ to_string(player_1.cardesTaken())+", draw rate:"+ to_string(getDrawRate()) \
    + ", win rate:"+ to_string(player_1.getWinRate())<<endl;
    

    cout<< player_2.getName()+": "<<endl;
    cout<<"cards won: "+ to_string(player_2.cardesTaken())+", draw rate:"+ to_string(getDrawRate()) \
    + ", win rate:"+ to_string(player_2.getWinRate())<<endl;
    
}

Game::Game(Player & ply1,Player & ply2) : player_1(ply1),player_2(ply2),draw_rate(0){
            if(player_1.getIn_game() || player_2.getIn_game()){
                throw exception();
            }
            string shapes[4]={"Hearts","Diamond","Clubs","Spades"};
            for(int i = 0;i<4;i++){
                string shape = shapes[i];
                for(int k=1 ;k<=13;k++){
                    Card card(k,shape);
                    stack.push_back(card);
                }
            }
            player_1.setIn_game(true);
            player_2.setIn_game(true);
            auto rd = std::random_device {}; 
            auto rng = std::default_random_engine { rd() };
            shuffle(begin(stack), end(stack), rng);
            player_1.setNextCard(0);
            player_2.setNextCard(26);
            player_1.setCardsInStack(26);
            player_2.setCardsInStack(26);
        }  
        

       
        
       
        