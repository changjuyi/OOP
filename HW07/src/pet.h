#pragma once
#include <string>

class Pet{
    public:
        Pet(){}
        Pet(std::string name,double weight){
            _name = name;
            _weight = weight;
        }
        std::string name(){
            return _name;
        }
        double weight(){
            return _weight;
        }
        virtual void feed()=0;
        virtual ~Pet(){}
    protected:
        std::string _name;
        double _weight;
};