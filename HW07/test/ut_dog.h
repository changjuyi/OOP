#pragma once
#include "../src/dog.h"
TEST(DogTest, Constructor){
    Dog d1("Apple",25);
    ASSERT_EQ("Apple",d1.name());
    ASSERT_NEAR(25,d1.weight(),0.3f);
    ASSERT_THROW(Dog("Apple",9),std::range_error);
    ASSERT_THROW(Dog("Apple",55),std::range_error);
}

TEST(DogTest,Feed){
    Dog d1("Apple",26);
    for(int i=0 ; i<4 ; i++){
        d1.feed();
    }
    ASSERT_NEAR(26+0.8*4,d1.weight(),0.3f);
    //ASSERT_NEAR(4+0.2*4+0.2*6,c1.weight(),0.3f);
    for(int i=0;i<26;i++){
        d1.feed();
    }
    ASSERT_NEAR(26+0.8*4+0.8*26,d1.weight(),0.3f);
    ASSERT_THROW(d1.feed(),std::out_of_range);
}