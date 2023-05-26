#include "../src/binary.h"
#include <string>
TEST(Binary_constructor, Sample1){
  int bits[8]={1,0,1,0,1,0,1,0};
  Binary a(bits,8);
  ASSERT_EQ("10101010",a.toString());
}

TEST(Binary_constructor, Sample2){
  int ab[6]={1,1,1,0,1,0};
  Binary a(ab,6);
  Binary b(a);
  ASSERT_EQ("111010",a.toString());
  ASSERT_EQ("111010",b.toString());
}

TEST(BinaryTest , exception1){
    int a[] ={};
    ASSERT_THROW(Binary b(a,0),std::string);
    //ASSERT_THROW(Binary c(),std::string);
}

TEST(BinaryTest, exception2){
    int a[3] = {0,-1,0};
    ASSERT_THROW(Binary b(a,3),std::string);
}

TEST(BinaryTest, exception3){
    int a[3] = {0,1,1};
    Binary b(a,3);
    ASSERT_THROW(b.resize(2),std::string);
}

TEST(BinaryTest, exception4){
    int a[3] = {0,1,1};
    Binary b(a,3);
    ASSERT_THROW(b.setBit(1,6),std::string);
    ASSERT_THROW(b.setBit(2,2),std::string);
}
/*
TEST(Binary_right_shift, Sample3){
  int ab[4]={1,1,1,0};
  Binary a(ab, 4);
  a>>2;
  ASSERT_EQ("0011",a.toString());
  a>>4;
  ASSERT_EQ("0000",a.toString());
}

TEST(Binary_right_shift, Sample4){
  Binary a;
  ASSERT_ANY_THROW(a>>1);
}
*/