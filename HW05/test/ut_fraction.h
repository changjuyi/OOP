#pragma once
#include "../src/fraction.h"
#include <gtest/gtest.h>
#include <string>
class FractionTest: public::testing::Test{
    protected:
        int a = (-3);
        Fraction f1;
        Fraction f2{-3};
        Fraction f3 = {1,2};
        Fraction f4{2,4};
        Fraction f5{3,2};
        Fraction f6{-3,1};
        Fraction f7{-3,2};
        Fraction add = f3 + f5;
        Fraction sub = f7 - f5;
        Fraction div = f6/f7;
        Fraction f8 = {-3,-2};
};

TEST_F(FractionTest, DefultConstructor){
    ASSERT_EQ(f1.numerator(),0);
    ASSERT_EQ(f1.denominator(),1);
    ASSERT_EQ(f1.sign(),'+');
}

TEST_F(FractionTest, OneParameterConstructor){
    ASSERT_EQ(f2.toString(),"-3");
    ASSERT_EQ(f2.sign(),'-');
    ASSERT_EQ(f2.numerator(),3);
    ASSERT_EQ(f2.denominator(),1);
}

TEST_F(FractionTest, TwoParameterConstructor){
    ASSERT_EQ(f3.sign(),'+');
    ASSERT_EQ(f3.numerator(),1);
    ASSERT_EQ(f3.denominator(),2);
    ASSERT_EQ(f3.toString(),"1/2");
    ASSERT_EQ(f4.sign(),'+');
    ASSERT_EQ(f4.numerator(),1);
    ASSERT_EQ(f4.denominator(),2);
    ASSERT_THROW(Fraction exp(1,0), std::string);
    ASSERT_EQ(f8.toString(),"3/2");
    ASSERT_EQ(f8.sign(),'+');

}

TEST_F(FractionTest, ToString){
    ASSERT_EQ(f5.toString(),"3/2");
    ASSERT_EQ(f6.toString(),"-3");
    ASSERT_EQ(f7.toString(),"-3/2");
}

TEST_F(FractionTest, OperatorAdd){
    ASSERT_EQ(add.toString(),"2");
}

TEST_F(FractionTest, OperatorSub){
    ASSERT_EQ(sub.toString(),"-3");
}

TEST_F(FractionTest, OperatorDiv){
    ASSERT_EQ(div.toString(),"2");
}

TEST_F(FractionTest, Numerator){
    ASSERT_EQ(f5.numerator(),3);
}

TEST_F(FractionTest, Denominator){
    ASSERT_EQ(f5.denominator(),2);
}

TEST_F(FractionTest, Sign){
    ASSERT_EQ(f5.sign(),'+');
}