#pragma once
#include <string>

class Toy {
    public:

    // constructor with parameter
    Toy(std::string name) { 
        toyname = name;
    }
    Toy(){
        
    }
    ~Toy() {}
    // get the name of the toy
    std::string getName() const { 
        return toyname;
    }

    private:
    std::string toyname;  
};
