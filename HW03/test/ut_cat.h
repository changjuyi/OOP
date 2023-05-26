#include "../src/cat.h"

#include <gtest/gtest.h>

// add your test here

TEST(CatTest, getname_1) {
  Cat c("Apple",3.5);
  int ans = c.getName().compare("Apple");
  ASSERT_EQ(ans, 0);
}
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