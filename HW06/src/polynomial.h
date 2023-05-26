#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>

#include "term.h"

class Polynomial {
public:
  Polynomial(std::vector<Term> terms, int degree) {
    _degree = degree;
    _terms = terms;
    std::stable_sort(_terms.begin(), _terms.end(), [](Term a, Term b){
      return a.exponent() < b.exponent();
    });
    for (int i = 0; i <= _degree; i++){
      if (i != 0){
        if (_terms[i - 1].exponent() == _terms[i].exponent()){
           throw std::string("with same exponent.");
        }
      }
      if (_terms[i].exponent() != i){
        _terms.insert(_terms.begin() + i, Term(0, i));
      }
      //std::cout << _terms[i].exponent() << std::endl;
    }
  }

  // get a term by exponent
  // If the term does not exist, return the term (0, exponent)
  Term term(int exponent) const {
    if (exponent > _degree){
      return Term(0, exponent);
    }else{
      return _terms[exponent];
    }
  }

  // get the degree
  int degree() const {
    return _degree;
  }

  // add two polynomials
  Polynomial operator+ (const Polynomial & q) const {
    int big_degree;
    if (this->_degree >= q._degree){
      big_degree = this->_degree;
    }else{
      big_degree = q._degree;
    }
    std::vector<Term> terms;
    for (int i = 0; i <= big_degree; i++){
      if (i <= this->_degree && i <= q._degree){
        terms.push_back(this->_terms[i] + q._terms[i]);
      }else if(i <= this->_degree){
         terms.push_back(this->_terms[i]);
      }else if(i <= q._degree){
         terms.push_back(q._terms[i]);
      }
    }

    if (big_degree != 0){
      for (int i = big_degree; i >= 0; i--){
        if (terms[i].coefficient() == 0.0){
          big_degree = i - 1;
        }else{
          break;
        }
      }
    }
    

    return Polynomial(terms, big_degree);

  }
  // multiply by a term
  Polynomial operator* (Term t) const {
    std::vector<Term> terms;
    for (int i = 0; i <= this->_degree; i++){
      terms.push_back(this->_terms[i] * t);
    }
    return Polynomial(terms, terms[this->_degree].exponent());
  }

  // multiply by another Polynomial
  Polynomial operator* (const Polynomial & q) const {
    std::vector<Term> sum_terms;
    int new_degree = this->_degree + q._degree;
    int count = 0;
    for (int i = 0; i <= q._degree; i++){
      if (q._terms[i].isZero()){
        count = count + 1;
        continue;
      }else if(sum_terms.empty()){
        for (int j = 0; j <= this->_degree; j++){
          sum_terms.push_back(this->_terms[j] * q._terms[i]);
        }
        count = 0;
      }else{
        for (int j = 0; j <= this->_degree; j++){
          if ((j + count) >= this->_degree){
            sum_terms.push_back(this->_terms[j] * q._terms[i]);
          }else{
            sum_terms[j + i] = sum_terms[j + i] + (this->_terms[j] * q._terms[i]);
          }
        }
        count = 0;
      }
    }
    return Polynomial(sum_terms, new_degree);
  }

private:
  std::vector<Term> _terms;
  int _degree;

};

#endif