#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/pet.h"
#include "../src/yard.h"

#include <gtest/gtest.h>
#include <vector>

class YardTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};

bool isPetsWeightover20(Pet *pet)
{
  return pet->weight() > 20;
}

bool isPetsWeightunder50(Pet *pet)
{
  return pet->weight() < 50;
}

TEST_F(YardTest, getPetWithConditionTestWithNormalfunction)
{
  Yard yard;
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
  std::vector<Pet *> pets;
  pets = yard.getPetWithCondition(isPetsWeightover20);
  ASSERT_EQ("Momos", pets[0]->name());
  ASSERT_NEAR(25, pets[0]->weight(), DELTA);
  ASSERT_EQ("Aoaos", pets[1]->name());
  ASSERT_NEAR(35, pets[1]->weight(), DELTA);
}

class isKindEqualCat
{
public:
  isKindEqualCat() {}

  bool operator()(Pet *pet)
  {
    return pet->kind() == "CAT";
  }
};

class isKindEqualDog
{
public:
  isKindEqualDog() {}

  bool operator()(Pet *pet)
  {
    return pet->kind() == "DOG";
  }
};

TEST_F(YardTest, getPetWithConditionTestWithFuntor1)
{
  Yard yard;
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
  std::vector<Pet *> pets;
  pets = yard.getPetWithCondition(isPetsWeightunder50);
  ASSERT_EQ("Bobos", pets[0]->name());
  ASSERT_NEAR(3, pets[0]->weight(), DELTA);
  ASSERT_EQ("Momos", pets[1]->name());
  ASSERT_NEAR(25, pets[1]->weight(), DELTA);
  ASSERT_EQ("Aoaos", pets[2]->name());
  ASSERT_NEAR(35, pets[2]->weight(), DELTA);
}

TEST_F(YardTest, getPetWithConditionTestWithFuntor2)
{
  Yard yard;
  yard.addPet(new Cat("Totos", 5));
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
  std::vector<Pet *> pets;
  pets = yard.getPetWithCondition(isKindEqualDog());
  ASSERT_EQ("Momos", pets[0]->name());
  ASSERT_NEAR(25, pets[0]->weight(), DELTA);
  ASSERT_EQ("Aoaos", pets[1]->name());
  ASSERT_NEAR(35, pets[1]->weight(), DELTA);
}

TEST_F(YardTest, getPetWithConditionTestWithLambda1)
{
  Yard yard;
  yard.addPet(new Cat("Totos", 5));
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
  std::vector<Pet *> pets;
  pets = yard.getPetWithCondition(
      [](Pet *pet)
      {
        return pet->weight() > 20;
      });
  ASSERT_EQ("Momos", pets[0]->name());
  ASSERT_NEAR(25, pets[0]->weight(), DELTA);
  ASSERT_EQ("Aoaos", pets[1]->name());
  ASSERT_NEAR(35, pets[1]->weight(), DELTA);
}

TEST_F(YardTest, getPetWithConditionTestWithLambda2)
{
  Yard yard;
  yard.addPet(new Cat("Totos", 5));
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
  std::vector<Pet *> pets;
  pets = yard.getPetWithCondition(
      [](Pet *pet)
      {
        return pet->kind() == "CAT";
      });
  ASSERT_EQ("Totos", pets[0]->name());
  ASSERT_NEAR(5, pets[0]->weight(), DELTA);
  ASSERT_EQ("Bobos", pets[1]->name());
  ASSERT_NEAR(3, pets[1]->weight(), DELTA);
}

TEST_F(YardTest, CopyConstructor)
{
  Yard yard;
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
  Yard yard1(yard);
  std::vector<Pet *> pets;
  pets = yard1.getPetWithCondition(isPetsWeightover20);
  ASSERT_EQ("Momos", pets[0]->name());
  ASSERT_NEAR(25, pets[0]->weight(), DELTA);
  ASSERT_EQ("Aoaos", pets[1]->name());
  ASSERT_NEAR(35, pets[1]->weight(), DELTA);
}

TEST_F(YardTest, CopyAssignment)
{
  Yard yard;
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
  Yard yard1(yard);
  std::vector<Pet *> pets;
  pets = yard1.getPetWithCondition(isPetsWeightover20);
  ASSERT_EQ("Momos", pets[0]->name());
  ASSERT_NEAR(25, pets[0]->weight(), DELTA);
  ASSERT_EQ("Aoaos", pets[1]->name());
  ASSERT_NEAR(35, pets[1]->weight(), DELTA);
}

TEST_F(YardTest, Destructor)
{
  Yard yard;
  yard.addPet(new Cat("Bobos", 3));
  yard.addPet(new Dog("Momos", 25));
  yard.addPet(new Dog("Aoaos", 35));
}