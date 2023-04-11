#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"

    using namespace ariel;
    using namespace std;
    size_t Player:: getNextCard(){
                int rev= nextCard++;
                cardsInStack--;
                return (size_t)rev;
    }
 
