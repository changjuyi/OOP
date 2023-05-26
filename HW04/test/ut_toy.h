#include "../src/toy.h"

#include <gtest/gtest.h>

// add your test here
TEST(ToyTest, getname) {
  Toy t("Apple");
  int ans = t.getName().compare("Apple");
  ASSERT_EQ(ans, 0);
}