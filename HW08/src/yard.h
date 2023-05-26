#ifndef YARD_H
#define YARD_H

#include <vector>

#include "pet.h"

class Yard
{
public:
  Yard() = default;

  Yard(Yard &yard)
  {
    //copyPets(yard._pets);
    CopyPet(yard._pets);
  }
  Yard operator=(Yard &yard)
  {
    //copyPets(yard._pets);
    CopyPet(yard._pets);
    return *this;
  }
  ~Yard()
  {
    for(int i=0;i<_pets.size();i++){
        if(_pets.at(i)!=nullptr){
          delete _pets.at(i);
          _pets.at(i)=nullptr;
        }
    }

  }
  void CopyPet(std::vector<Pet *> pet){
    std::vector<Pet *> pets;
    for(int i=0;i<pet.size();i++){
      if(pet[i]->kind() == "CAT"){
        pets.push_back(new Cat(pet[i]->name(),pet[i]->weight()));
      }else{
        pets.push_back(new Dog(pet[i]->name(),pet[i]->weight()));
      }
    }
    destoryPets();
    _pets = pets;
  }
  void addPet(Pet *pet)
  {
    _pets.push_back(pet);
  }
  template <typename Condition>
  std::vector<Pet *> getPetWithCondition(Condition cond)
  {
    std::vector<Pet *> pets_in_cond;
    for (Pet *pet : _pets)
    {
      if (cond(pet))
      {
        pets_in_cond.push_back(pet);
      }
    }
    return pets_in_cond;
  }

private:
  std::vector<Pet *> _pets;
  void destoryPets()
  {
    for (int i = 0; i < _pets.size(); i++)
    {
      if (_pets.at(i) != nullptr)
      {
        delete _pets.at(i);
        _pets.at(i) = nullptr;
      }
    }
  }
  /*
  void copyPets(std::vector<Pet *> pets)
  {
    std::vector<Pet *> newPets;
    for (int i = 0; i < pets.size(); i++)
    {
      if (pets[i]->kind() == "CAT")
      {
        newPets.push_back(new Cat(pets[i]->name(), pets[i]->weight()));
      }
      else
      {
        newPets.push_back(new Dog(pets[i]->name(), pets[i]->weight()));
      }
    }
    destoryPets();
    _pets = newPets;
  }
  */
};

#endif /* end of include guard: YARD_H */