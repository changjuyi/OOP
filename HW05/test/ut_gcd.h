#pragma once
#include "../src/gcd.h"
#include <gtest/gtest.h>

TEST(GcdTest, AllPositive){
    int a=34,b=10;
    ASSERT_EQ(gcd(b,a),2);
}
TEST(GcdTest, OneNegative){
    int a=(-34),b=10;
    ASSERT_EQ(gcd(a,b),2);
}