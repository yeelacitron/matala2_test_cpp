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
            Card(int value_, std::string shape_):value(value_),shape(std::move(shape_)){}
        size_t getValue() const{
            return (size_t)value;
        }
        std::string getShape() const{
            return shape;
        }
            
            
    };

}




