#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace ariel{
        class Card
    {
        private:
            std::string shape;
            int value;
        public:
            Card(int value_, std::string shape_):value(value_),shape(shape_){}
        size_t getValue(){
            return (size_t)value;
        }
        std::string getShape(){
            return shape;
        }
            
            
    };

}




