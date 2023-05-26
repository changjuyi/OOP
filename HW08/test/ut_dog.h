#include "../src/dog.h"
#include "../src/pet.h"

#include <stdexcept>


class DogTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};


TEST_F(DogTest, AmountConstructor) {
  Dog dog("Dog", 30);
  ASSERT_EQ(1, Dog::amount());
}

TEST_F(DogTest, AmountCopyConstructor) {
  Dog dog_1("Dog", 30);
  Dog dog_2 = dog_1;
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(DogTest, AmountPolymorphism) {
  Pet * pet = new Dog("Dog", 30);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Dog::amount());
  delete pet;
}

TEST_F(DogTest,Constructor){
  Dog dog("Dog",30);
  ASSERT_EQ("Dog",dog.name());
  ASSERT_EQ(30,dog.weight());
}

TEST_F(DogTest,feed){
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