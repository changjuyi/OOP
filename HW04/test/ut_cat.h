#include "../src/cat.h"
#include "../src/toy.h"
#include <gtest/gtest.h>

// add your test here

TEST(CatTest, constructor1){
  //Cat c("",20);
  ASSERT_THROW(Cat c("",20), std::string);
}

TEST(CatTest, constructor2){
  ASSERT_THROW(Cat c("Apple",5), std::string);
}

TEST(CatTest, CopyCon){
  Cat c1("Apple",20);
  Cat c2(c1);
  int a = c2.getName().compare(c1.getName());
  ASSERT_EQ(a,0);
  ASSERT_NEAR(c1.getWeight(), c2.getWeight(), 0.3f);
}

TEST(CatTest, CopyAss){
  Cat c1("Apple",20),c2("Candy",25);
  c2 = c1;
  int a = c2.getName().compare(c1.getName());
  ASSERT_EQ(a,0);
  ASSERT_NEAR(c1.getWeight(), c2.getWeight(), 0.3f);
}

TEST(CatTEST, AddNewToy){
  Toy t("rat");
  Cat c("Apple",20);
  c.addNewToy(t);
  int a = c.getToyAmount();
  ASSERT_EQ(a,1);
}

TEST(CatTest, getToy){
  Cat c("Apple",15);
  Toy t1("rat"),t2("rabbit");
  c.addNewToy(t1);
  c.addNewToy(t2);
  int a = c.getToy(0).getName().compare("rat");
  int b = c.getToy(1).getName().compare("rabbit");
  ASSERT_EQ(a,0);
  ASSERT_EQ(b,0);
  ASSERT_THROW(c.getToy(2) , std::string);
}

TEST(CatTest, isHeavier){
  Cat c1("Apple",15),c2("Candy",20);
  ASSERT_FALSE(c1.isHeavierThan(c2));
  ASSERT_TRUE(c2.isHeavierThan(c1));
}
/*
TEST(CatTest, getname_2) {
  Cat c("Candy",5.6);
  int ans = c.getName().compare("Candy");
  ASSERT_EQ(ans, 0);
}
TEST(CatTest, getweight_1) {
  Cat c("Apple",3.5);
  ASSERT_NEAR(3.5, c.getWeight(), 0.3f);
}
TEST(CatTest, getweight_2) {
  Cat c("Candy",5.6);
  ASSERT_NEAR(5.6, c.getWeight(), 0.3f);
}
TEST(CatTest, addNewToy_1){
    Cat c("Apple",3.5);
    c.addNewToy("rat");
    int a = c.getToyAmount();
    ASSERT_EQ(a,1);
}
TEST(CatTest, addNewToy_2){
    Cat c("Apple",3.5);
    c.addNewToy("rat");
    c.addNewToy("rabbit");
    ASSERT_EQ(c.getToyAmount(),2);
}
TEST(CatTest, getToy_1){
    Cat c("Apple", 3.5);
    c.addNewToy("rat");
    c.addNewToy("rabbit");
    c.addNewToy("Teaser");
    c.addNewToy("Tree");
    c.addNewToy("Scratcher");
    int ans = c.getToy(0).compare("rat");
    ASSERT_EQ(ans,0);
}
TEST(CatTest, getToy_2){
    Cat c("Apple", 3.5);
    c.addNewToy("rat");
    c.addNewToy("rabbit");
    c.addNewToy("Teaser");
    c.addNewToy("Tree");
    c.addNewToy("Scratcher");
    int ans = c.getToy(3).compare("Tree");
    ASSERT_EQ(ans,0);
}
*/