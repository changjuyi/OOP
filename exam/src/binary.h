#ifndef Binary_H
#define Binary_H
#include <vector>
#include <string>
#include <math.h>
#include <bitset>
class Binary{
public:
    Binary(){
        throw new std::string("binary number is not initialized with binary digits");
    }
    Binary(int input[],int s){
        if(s==0){
            throw std::string("binary number is not initialized with binary digits");
        }
        for(int i=0;i<s;i++){
            bin.push_back(input[i]);
            if((bin[i]!=1) && (bin[i]!=0)){
                throw std::string("binary digit only 0 and 1");
            }
            if(bin[i]<0){
                throw std::string("need postive digit");
            }
        }
    }
    Binary(const Binary & b){ 
        bin.assign(b.bin.begin(),b.bin.end());
    }
    ~Binary(){ }
    Binary & operator=(Binary const &b){ 
        bin.assign(b.bin.begin(),b.bin.end());
        return *this;
    }
    Binary operator+(Binary  &b){ 
        Binary a;
        return a; 
    }
    Binary operator-(Binary &b){
        Binary a;
        return a;
    }
    Binary operator>>(int a){
        Binary a;
        return a;
    }
    Binary operator<<(int a){
        Binary a;
        return a;
    }
    void resize(int new_size){
        if(new_size < bin.size()){
            throw std::string("size wrong");
        }
        for(int i=0 ; i<(new_size-bin.size()) ; i++){
            bin.insert(bin.begin(),0);
        }
    }
    void setBit(int pos,int a){
        if(a >= bin.size()){
            throw std::string("out of bound");
        }
        if((pos!=0) && (pos!=1)){
            throw std::string("data only 0 and 1");
        }
        bin[a]=pos;
    }
    int toInt() const{
        int res=0;
        for(int i=0; i<bin.size(); i++){
            res+=(int)bin[i]*pow(2,i);
        }
        return res;
    }
    std::string toString() const{
        std::string res;
        for(int i=0;i<bin.size();i++){
            res+=std::to_string(bin[i]);
        }
        return res;
    }
private :
    std::vector<int> bin;
};

#endif
