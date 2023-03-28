#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel{
    class Player{
        public:
            string name;
            int stacksize();
            int cardesTaken();
        

        Player(string name_){
            name = name_;
        }
    };
}
