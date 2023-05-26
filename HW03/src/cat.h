#include <string>

class Cat {
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
