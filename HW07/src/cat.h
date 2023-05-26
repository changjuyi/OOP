#pragma once
#include "pet.h"

class Cat:public Pet{
    public:
        Cat(){}
        Cat(std::string name,double weight):Pet(name,weight){
            if(weight<2 || weight>6){
                throw std::range_error("weight <2 or weight >6!");
            }
        }
        void feed() override{
             _weight = _weight+0.2;
            if(_weight>6){
                throw std::out_of_range("weight >6!");
            }
            
        }
        ~Cat() override{}
};