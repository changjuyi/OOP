#pragma once
#include <string>
#include "./gcd.h"
class Fraction {
public:

  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1
  Fraction() {
    _sign='+';
    _numerator = 0;
    _denominator = 1;
  }

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
  Fraction(int num) {
    if(num<0){
      _sign='-';
      _numerator = num*(-1);
      _denominator = 1;
    }else{
      _sign = '+';
      _numerator = num;
      _denominator = 1;
    }
  }

  // hint: use gcd
  // throw exception when the denominator is 0
  Fraction(int numerator, int denominator) {
    if(denominator==0){
      throw std::string ("undefined");
    }
    int r = gcd(numerator,denominator);
    _numerator = numerator / r;
    _denominator = denominator / r;
    int a = _denominator * _numerator;
    if(a<0){
      //dm<0 , d<0 or n<0
      _sign = '-';
      if(_numerator<0){
        _numerator *=(-1);
      }
      if(_denominator<0){
        _denominator *=(-1);
      }
    }else{
      //dn>0, d<0 and n<0 or d>0 and n>0
      _sign = '+';
      if(_numerator<0){
        _numerator *=(-1);
      }
      if(_denominator<0){
        _denominator *=(-1);
      }
    }
    /*
    if(numerator<0 && denominator<0){
      _sign = '+';
      _numerator = numerator*(-1);
      _denominator = denominator*(-1);
    }else if(numerator>0 && denominator>0){
      _sign = '+';
      _numerator = numerator;
      _denominator = denominator;
    }else{
      _sign = '-';
      if(numerator<0){
        _numerator = numerator*(-1);
        _denominator = denominator;
      }
      if(denominator<0){
        _numerator = numerator;
        _denominator = denominator*(-1);
      }
    }
    */
    /*
    if((numerator<0) && (denominator<0)){
      _sign = '+';
      numerator *=(-1);
      denominator *=(-1);
    }else if(numerator>0 && denominator>0){
      _sign = '+';
    }else{
      _sign = '-';
      if(numerator<0){
        numerator *=(-1);
      }
      if(denominator<0){
         denominator = denominator*(-1);
      }
    }
    int r = gcd(numerator,denominator);
    _numerator = numerator/r;
    _denominator = denominator/r;  
    */
  }

  // get the numerator of the fraction
  int numerator() const {
    return _numerator;
  }

  // get the denominator of the fraction
  int denominator() const {
    return _denominator;
  }

  // get positive or negative sign of the fraction
  char sign() const {
    return _sign;
  }

  // display the fraction by string
  std::string toString() const {
    std::string res;
    if(this->_sign=='+'){
      if(_denominator==1 || _numerator==0){
        res = std::to_string(_numerator);
      }else{
        res = std::to_string(_numerator) + "/" + std::to_string(_denominator);
      }
    }else{
      std::string sign_str(1, _sign);
      if(_denominator==1){
        if(_numerator==0){
          res = std::string("0");
        }else{
          res = sign_str + std::to_string(_numerator);
        }
      }else{
        res = sign_str + std::to_string(_numerator) + "/" + std::to_string(_denominator);
      }
    }
    return res;
    /*
    if(this->_sign=='+'){
      if(_denominator==1 || _numerator==0){
        res = std::to_string(_numerator);
      }else{
        res = std::to_string(_numerator) + "/" + std::to_string(_denominator);
      }
    }else{
      std::string sign_string( 1, _sign);
      if(_denominator==1){
        res = sign_string + std::to_string(_numerator);       
      }else if(_numerator==0){
        res = std::to_string(_numerator);
      }else{
        res = sign_string + std::to_string(_numerator) + "/" + std::to_string(_denominator);
      }
    }
    */
    
  }

  // addition of two Fractions
  Fraction operator + (Fraction const & f) const {
    int num1,dem1,num2,dem2,add_num,add_dem;
    if(this->_sign=='-'){
      num1 = this->_numerator*(-1);
      dem1 = this->_denominator;
    }else{
      num1 = this->_numerator;
      dem1 = this->_denominator;
    }
    if(f._sign=='-'){
      num2 = f._numerator*(-1);
      dem2 = f._denominator;
    }else{
      num2 = f._numerator;
      dem2 = f._denominator;
    }
    add_num = num1*dem2 + num2*dem1;
    add_dem = dem1*dem2;
    Fraction add(add_num,add_dem);
    return add;
  }

  // subtraction of two Fractions
  Fraction operator - (Fraction const & f) const {
    int num1,dem1,num2,dem2,sub_num,sub_dem;
    if(this->_sign=='-'){
      num1 = this->_numerator*(-1);
      dem1 = this->_denominator;
    }else{
      num1 = this->_numerator;
      dem1 = this->_denominator;
    }
    if(f._sign=='-'){
      num2 = f._numerator*(-1);
      dem2 = f._denominator;
    }else{
      num2 = f._numerator;
      dem2 = f._denominator;
    }
    sub_num = num1*dem2 - num2*dem1;
    sub_dem = dem1*dem2;
    Fraction sub(sub_num,sub_dem);
    return sub;
  }

  // division of two Fractions
  Fraction operator / (Fraction const & f) const {
    int num1,dem1,num2,dem2,div_num,div_dem;
    if(this->_sign=='-'){
      num1 = this->_numerator*(-1);
      dem1 = this->_denominator;
    }else{
      num1 = this->_numerator;
      dem1 = this->_denominator;
    }
    if(f._sign=='-'){
      num2 = f._numerator*(-1);
      dem2 = f._denominator;
    }else{
      num2 = f._numerator;
      dem2 = f._denominator;
    }
    div_num = num1*dem2;
    div_dem = dem1*num2;
    Fraction div(div_num,div_dem);
    return div;
  }

private:
  // both numerator and denominator should be positive
  int _numerator;
  int _denominator;
  char _sign;
};
