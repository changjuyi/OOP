#pragma once
#include <string>
#include <vector>
#include <exception>
#include "./toy.h"

class Cat {
public:
    Cat(std::string name, double weight) {
        _name = name;
        _weight = weight;
        if((_weight<10) || (_weight>50)){
            throw std::string ("weight range wrong");
        }
        if (_name.compare("")==0){
            throw std::string ("no name");
        }
        toyAmount=0;
    }

    ~Cat() {}

    std::string getName() {
        return _name;
    }

    double getWeight() {
        return _weight;
    }

    // copy constructor
    Cat(Cat const & other) {    
        _name = other._name;
        _weight = other._weight;
        toycollections.assign(other.toycollections.begin(), other.toycollections.end());
    }

    // copy assignment
    Cat & operator = (Cat const & other) {
        this -> _name = other._name;
        this -> _weight = other._weight;
        toycollections.assign(other.toycollections.begin(), other.toycollections.end());
        return * this;
    }

    // add Toy in toy collections
    void addNewToy(Toy const & toyName) { 
        toycollections.push_back(toyName);
        toyAmount++;
    }
    int getToyAmount(){
      return toyAmount;
    }
    // index from 0
    Toy getToy(int index) const { 
        if(index>=toycollections.size()){
            throw std::string ("out of range");
        }else{
            return toycollections[index];
        }
       
    }

    // true if heavier than (>) other
    bool isHeavierThan(Cat const & other) const {
        if(this->_weight > other._weight){
            return true;
        }else{
            return false;
        }
    }

private:
    std::string _name;
    double _weight;
    std::vector<Toy> toycollections;
    int toyAmount;
};

/*class Cat {
public:

  Cat(std::string name, double weight) {
      _name = name;
      _weight = weight;
      _toyAmount=0;
      _toyCollections = nullptr;
  }

  ~Cat() {}

  std::string getName() {
      return _name;
  }

  double getWeight() {
      return _weight;
  }

  void addNewToy(std::string toyName) {
      _toyAmount++;
      std::string *tmp = new std::string[_toyAmount];
      for(int i = 0;i < _toyAmount -1; i++){
          tmp[i] = _toyCollections[i];
      }
      tmp[_toyAmount - 1] = toyName;
      delete [] _toyCollections;
      _toyCollections = tmp;
  }

  std::string getToy(int index) {
      return _toyCollections[index];
  }
  int getToyAmount(){
      return _toyAmount;
  }
private:
  std::string _name;
  double _weight;
  std::string * _toyCollections;
  int _toyAmount;

};
*/