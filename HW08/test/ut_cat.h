#include "../src/cat.h"
#include "../src/pet.h"

#include <stdexcept>


class CatTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }

  const double DELTA = 0.001;
};


TEST_F(CatTest, AmountConstructor) {
  Cat cat("Cat", 3);
  ASSERT_EQ(1, Cat::amount());
}

TEST_F(CatTest, AmountCopyConstructor) {
  Cat cat_1("Cat", 3);
  Cat cat_2 = cat_1;
  ASSERT_EQ(2, Cat::amount());
}

TEST_F(CatTest, AmountPolymorphism) {
  Pet * pet = new Cat("Cat", 3);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Cat::amount());
  delete pet;
}

TEST_F(CatTest,Constructor){
  Cat cat("Cat",3);
  ASSERT_EQ("Cat",cat.name());
  ASSERT_EQ(3,cat.weight());
}

TEST_F(CatTest,feed){
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