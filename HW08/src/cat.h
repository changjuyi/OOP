#ifndef CAT_H
#define CAT_H

#include <stdexcept>
#include <string>

#include "pet.h"


class Cat : public Pet {
public:

  /*  add and modify your code from assignment 8  */
  Cat(std::string name, double weight):Pet("CAT",name,weight){
    if((this->weight() < 2) || (this->weight() > 6)){
      throw std::range_error("weight < 2 or weight > 6");
    }
    AddAmount();
  }
  virtual ~Cat() override{
    MinusAmount();
  }
  Cat(const Cat &c):Pet(c){
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
    _weight+=0.2;
    if((_weight > 6)){
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

int Cat::_amount = 0;


#endif /* end of include guard: CAT_H */
