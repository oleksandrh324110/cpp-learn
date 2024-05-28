#include <gtest/gtest.h>

#include "../src/hashmap.h"

TEST(HashMapTest, InsertAndContainsTest) {
  std::hashmap<int, std::string> map;
  map.insert(1, "one");
  map.insert(2, "two");
  map.insert(3, "three");

  ASSERT_TRUE(map.contains(1));
  ASSERT_TRUE(map.contains(2));
  ASSERT_TRUE(map.contains(3));
  ASSERT_FALSE(map.contains(4));
}

TEST(HashMapTest, RemoveTest) {
  std::hashmap<int, std::string> map;
  map.insert(1, "one");
  map.insert(2, "two");
  map.insert(3, "three");

  map.remove(2);

  ASSERT_TRUE(map.contains(1));
  ASSERT_FALSE(map.contains(2));
  ASSERT_TRUE(map.contains(3));
}

TEST(HashMapTest, OperatorTest) {
  std::hashmap<int, std::string> map;
  map.insert(1, "one");
  map.insert(2, "two");
  map.insert(3, "three");

  ASSERT_EQ(map[1].value, "one");
  ASSERT_EQ(map[2].value, "two");
  ASSERT_EQ(map[3].value, "three");
}

TEST(HashMapTest, UpdateValueTest) {
  std::hashmap<int, std::string> map;
  map.insert(1, "one");
  map.insert(2, "two");
  map.insert(3, "three");

  map[1] = "uno";
  map[2] = "dos";
  map[3] = "tres";

  ASSERT_EQ(map[1].value, "uno");
  ASSERT_EQ(map[2].value, "dos");
  ASSERT_EQ(map[3].value, "tres");
}

TEST(HashMapTest, InsertAfterRemoveTest) {
  std::hashmap<int, std::string> map;
  map.insert(1, "one");
  map.insert(2, "two");
  map.insert(3, "three");

  map.remove(2);
  map.insert(2, "dos");

  ASSERT_TRUE(map.contains(2));
  ASSERT_EQ(map[2].value, "dos");
}
