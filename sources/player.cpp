#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"

    using namespace ariel;
    using namespace std;
    int Player:: stacksize(){
        return 52/2;
    }
    int Player:: cardesTaken(){
        return 5;
    }
