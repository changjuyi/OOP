#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../src/polynomial.h"
#include "../src/term.h"
class PolynomialTest: public::testing::Test{
    protected:
        Term t1(2, 1),t2(1,0),t3(1,2);
        std::vector<Term> terms1 = {Term(-3,2),Term(3,0),Term(6,3)};
        std::vector<Term> terms2 = {Term(-3,2),Term(3,2),Term(6,3)};
        std::vector<Term> terms3 = {t3, t2, Term(-1, 3)};
        std::vector<Term> terms4 = {t3, t2, Term(1, 1), Term(1, 3)};
        std::vector<Term> terms5 = {t3, t2, Term(2, 1)};
        std::vector<Term> terms6 = {t3, t2, Term(1, 1)};
        std::vector<Term> terms7 = {t2, t1};
        
        Polynomial p1(terms1,3); 
        Polynomial p3(terms3, 3);
        Polynomial p4(terms4, 3);
        Polynomial p5(terms5, 2);
        Polynomial p6(terms6, 2);
        Polynomial p7(terms7, 1);
        Polynomial addresult = p3 + p4;
        Polynomial multermresult = p5 * t;
        Polynomial mulpolyresult = p6 * p7;
}
TEST_F(PolynomialTest, Constructor){
    ASSERT_EQ(3, p1.degree());
    ASSERT_EQ(0, p1.term(0).exponent());
    ASSERT_EQ(1, p1.term(1).exponent());
    ASSERT_EQ(2, p1.term(2).exponent());
    ASSERT_EQ(3, p1.term(3).exponent());
    ASSERT_EQ(3.0, p1.term(0).coefficient());
    ASSERT_EQ(0.0, p1.term(1).coefficient());
    ASSERT_EQ(-3.0, p1.term(2).coefficient());
    ASSERT_EQ(6.0, p1.term(3).coefficient());

    ASSERT_THROW(Polynomial p2(term2,3),std::string);
}
TEST_F(PolynomialTest,GetTerm){
    ASSERT_EQ(2, p1.term(2).exponent());
    ASSERT_EQ(-3.0, p1.term(2).coefficient());

    ASSERT_EQ(5, p1.term(5).exponent());
    ASSERT_EQ(0.0, p1.term(5).coefficient());
}
TEST_F(PolynomialTest, Add){
    ASSERT_EQ(2, addresult.degree());
    ASSERT_EQ(2.0, addresult.term(0).coefficient());
    ASSERT_EQ(1.0, addresult.term(1).coefficient());
    ASSERT_EQ(2.0, addresult.term(2).coefficient());
    ASSERT_EQ(0.0, addresult.term(3).coefficient());
}
TEST_F(PolynomialTest, MulTerm){
    ASSERT_EQ(3, multermresult.degree());
    ASSERT_EQ(0, multermresult.term(0).exponent());
    ASSERT_EQ(0.0, multermresult.term(0).coefficient());
    ASSERT_EQ(1, multermresult.term(1).exponent());
    ASSERT_EQ(2.0, multermresult.term(1).coefficient());
    ASSERT_EQ(2,multermresult.term(2).exponent());
    ASSERT_EQ(4.0, multermresult.term(2).coefficient());
    ASSERT_EQ(3, multermresult.term(3).exponent());
    ASSERT_EQ(2.0, multermresult.term(3).coefficient());
}
TEST_F(PolynomialTest, MulPoly){
    ASSERT_EQ(3, mulpolyresult.degree());
    ASSERT_EQ(0, mulpolyresult.term(0).exponent());
    ASSERT_EQ(1.0, mulpolyresult.term(0).coefficient());
    ASSERT_EQ(1, mulpolyresult.term(1).exponent());
    ASSERT_EQ(3.0, mulpolyresult.term(1).coefficient());
    ASSERT_EQ(2, mulpolyresult.term(2).exponent());
    ASSERT_EQ(3.0, mulpolyresult.term(2).coefficient());
    ASSERT_EQ(3, mulpolyresult.term(3).exponent());
    ASSERT_EQ(2.0, mulpolyresult.term(3).coefficient());
}