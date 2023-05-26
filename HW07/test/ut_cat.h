#pragma once
#include "../src/cat.h"
#include <gtest/gtest.h>
#include <string>

TEST(CatTest, Constructor){
    Cat c1("Apple",5);
    ASSERT_EQ("Apple",c1.name());
    ASSERT_NEAR(5,c1.weight(),0.3f);
    ASSERT_THROW(Cat("Apple",8),std::range_error);
}

TEST(CatTest,Feed){
    Cat c1("Apple",4);
    for(int i=0 ; i<4 ; i++){
        c1.feed();
    }
    ASSERT_NEAR(4+0.2*4,c1.weight(),0.3f);
    for(int i=0;i<5;i++){
        c1.feed();
    }
    ASSERT_NEAR(4+0.2*4+0.2*5,c1.weight(),0.3f);
    ASSERT_THROW(c1.feed(),std::out_of_range);
}