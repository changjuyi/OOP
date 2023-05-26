#include "../src/algo.h"
#include "../src/cat.h"
#include "../src/dog.h"
#include <gtest/gtest.h>
#include <vector>
class AlgoTest: public::testing::Test{
    protected:
        std::vector<Pet *> pets;
        void SetUp() override{
            Pet *p1 = new Cat("Apple",5);
            Pet *p2 = new Cat("Mary",4);
            Pet *p3 = new Dog("Ted",45);
            Pet *p4 = new Dog("Eve",25);
            pets.insert(pets.begin(),{p1,p2,p3,p4});
        }
        void TearDown() override{
            for(Pet *p : pets){
                delete p;
            }
        }
};

TEST_F(AlgoTest, MaxName){
    Pet *max_name = *maxPet(pets.begin(), pets.end(), pet_comp::longerName);
    ASSERT_EQ("Apple",max_name->name());
    ASSERT_NEAR(5,max_name->weight(),0.3f);
}

TEST_F(AlgoTest, MaxWeight){
    Pet *max_weight = *maxPet(pets.begin(), pets.end(), pet_comp::largerWeight);
    ASSERT_EQ("Ted",max_weight->name());
    ASSERT_NEAR(45,max_weight->weight(),0.3f);
}
/*
TEST(AlgoTest, maxPet){
    std::vector<Pet *> pets(4);
    Cat c1("Apple",5),c2("cat",4);
    Dog d1("do",25),d2("tree",45);
    pets[0] = &c1;
    pets[1] = &c2;
    pets[2] = &d1;
    pets[3] = &d2;
    Pet *max_weight = *maxPet(pets.begin(), pets.end(), pet_comp::largerWeight);
    Pet *max_name = *maxPet(pets.begin(), pets.end(), pet_comp::longerName);

    ASSERT_NEAR(45,max_weight->weight(),0.3f);
    ASSERT_EQ("Apple",max_name->name());
    
}
*/