#ifndef DOG_H
#define DOG_H

#include <stdexcept>
#include <string>

#include "pet.h"


class Dog : public Pet {
public:

  /*  add and modify your code from assignment 8  */
  Dog(std::string name, double weight):Pet("DOG",name,weight){
    if((this->weight() < 10) || (this->weight() > 50)){
      throw std::range_error("weight < 10 or weight > 50");
    }
    AddAmount();
  }
  virtual ~Dog() override{
   MinusAmount();
  }
  Dog(const Dog &d):Pet(d){
    AddAmount();
  }
  static void AddAmount(){
    _amount++;
  }
  static void MinusAmount(){
    if(_amount > 0){
       _amount--;
    }
  }
  virtual void feed() override{
    double _weight = this->weight();
    _weight += 0.8;
    if((_weight > 50)){
      throw std::out_of_range("Feed too much");
    }
    this->setWeight(_weight);
  }
  
  static int amount() {
    return _amount;
  }

private:
  static int _amount;

};

int Dog::_amount = 0;


#endif /* end of include guard: DOG_H */
