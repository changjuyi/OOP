#pragma once
#include <string>
#include "pet.h"

class Dog:public Pet{
    public:
        Dog(std::string name,double weight):Pet(name,weight){
            if(weight<10 || weight>50){
                throw std::range_error("range error!");
            }
        }
        virtual void feed() override{
            _weight+=0.8;
            if(_weight>50){
                throw std::out_of_range("out of range!");
            }
        }
        ~Dog() override{}
};