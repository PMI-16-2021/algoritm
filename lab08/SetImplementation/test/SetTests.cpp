#include <MySet.h>
#include <gtest/gtest.h>

TEST(SetTestSuite, creationTest) {
    MySet<int> setOfIntegers;
    setOfIntegers.Add(5);
    setOfIntegers.Add(11);
    setOfIntegers.Add(-7);
    setOfIntegers.Add(10);
    setOfIntegers.Add(0);
    int integersArray[5] = {5, 11, -7, 10, 0};
    for (int i = 0; i < setOfIntegers.Length(); ++i) {
        EXPECT_EQ(setOfIntegers[i], integersArray[i]);
    }
    MySet<std::string> setOfStrings(2);
    std::string arrayOfStrings[3] = {"Heeey", "Noo", "Yeees"};
    setOfStrings.Add("Heeey");
    setOfStrings.Add("Noo");
    setOfStrings.Add("Yeees");
    for (int i = 0; i < setOfStrings.Length(); ++i) {
        EXPECT_EQ(setOfStrings[i], arrayOfStrings[i]);
    }
}

TEST(SetTestSuite, ContainsTest) {
    MySet<std::string> setOfStrings;
    setOfStrings.Add("Heeey");
    setOfStrings.Add("Noo");
    setOfStrings.Add("Yeees");
    EXPECT_TRUE(setOfStrings.Contains("Heeey"));
    EXPECT_FALSE(setOfStrings.Contains("Boooo"));
    MySet<int> setOfIntegers;
    setOfIntegers.Add(5);
    setOfIntegers.Add(11);
    setOfIntegers.Add(-7);
    setOfIntegers.Add(10);
    setOfIntegers.Add(0);
    EXPECT_TRUE(setOfIntegers.Contains(11));
    EXPECT_TRUE(setOfIntegers.Contains(0));
    EXPECT_FALSE(setOfIntegers.Contains(-8));
    EXPECT_FALSE(setOfIntegers.Contains(-11));
}

TEST(SetTestSuite, LengthTest) {
    MySet<std::string> setOfStrings;
    setOfStrings.Add("Heeey");
    setOfStrings.Add("Noo");
    setOfStrings.Add("Yeees");
    EXPECT_EQ(3, setOfStrings.Length());
    MySet<int> setOfIntegers;
    setOfIntegers.Add(5);
    setOfIntegers.Add(11);
    setOfIntegers.Add(-7);
    setOfIntegers.Add(10);
    setOfIntegers.Add(0);
    EXPECT_EQ(5, setOfIntegers.Length());
    setOfIntegers.Remove(-7);
    EXPECT_EQ(4, setOfIntegers.Length());
}

TEST(SetTestSuite, AddTest) {
    MySet<std::string> setOfStrings;
    setOfStrings.Add("Heeey");
    setOfStrings.Add("Noo");
    setOfStrings.Add("Yeees");
    setOfStrings.Add("Gail");
    setOfStrings.Add("Lenny");
    setOfStrings.Add("Mike Divine");
    setOfStrings.Add("Barby");
    std::string arrayOfStrings[10] = {"Heeey", "Noo", "Yeees", "Gail", "Lenny", "Mike Divine", "Barby"};
    for (int i = 0; i < setOfStrings.Length(); ++i) {
        EXPECT_EQ(setOfStrings[i], arrayOfStrings[i]);
    }
    //check if add works correct after removing such element
    MySet<int> setOfIntegers(2);
    setOfIntegers.Add(5);
    setOfIntegers.Add(11);
    setOfIntegers.Add(-7);
    setOfIntegers.Add(10);
    setOfIntegers.Add(0);
    setOfIntegers.Remove(11);
    setOfIntegers.Add(11);
    int arrayOfIntegers[6] = {5, -7, 10, 0, 11};
    for (int i = 0; i < setOfIntegers.Length(); ++i) {
        EXPECT_EQ(setOfIntegers[i], arrayOfIntegers[i]);
    }
    EXPECT_THROW(setOfIntegers.Add(5), NotUniqueElementException<int>);
}

TEST(SetTestSuite, RemoveTest) {
    MySet<std::string> setOfStrings;
    setOfStrings.Add("Heeey");
    setOfStrings.Add("Noo");
    setOfStrings.Add("Yeees");
    setOfStrings.Add("Gail");
    setOfStrings.Add("Lenny");
    setOfStrings.Add("Mike Divine");
    setOfStrings.Add("Barby");
    std::string arrayOfStrings[9] = {"Heeey", "Noo", "Yeees", "Lenny", "Mike Divine", "Barby"};
    setOfStrings.Remove("Gail");
    EXPECT_FALSE(setOfStrings.Contains("Gail"));
    for (int i = 0; i < setOfStrings.Length(); ++i) {
        EXPECT_EQ(setOfStrings[i], arrayOfStrings[i]);
    }

    MySet<int> setOfIntegers(2);
    setOfIntegers.Add(5);
    setOfIntegers.Add(11);
    setOfIntegers.Add(-7);
    setOfIntegers.Add(10);
    setOfIntegers.Add(0);
    setOfIntegers.Remove(11);
    int arrayOfIntegers[6] = {5, -7, 10, 0};
    for (int i = 0; i < setOfIntegers.Length(); ++i) {
        EXPECT_EQ(setOfIntegers[i], arrayOfIntegers[i]);
    }
    EXPECT_FALSE(setOfIntegers.Contains(11));
    EXPECT_THROW(setOfIntegers.Remove(12), ElementNotFoundException<int>);
}

TEST(SetTestSuite, UnionTest) {
    MySet<int> mySet1;
    mySet1.Add(1);
    mySet1.Add(2);
    mySet1.Add(3);
    mySet1.Add(4);
    mySet1.Add(5);

    MySet<int> mySet2;
    mySet2.Add(10);
    mySet2.Add(11);
    mySet2.Add(12);
    mySet2.Add(13);
    mySet2.Add(14);
    mySet2.Add(5);
    mySet2.Add(3);
    int unionArrayOfIntegers[10] = {1, 2, 3, 4, 5, 10, 11, 12, 13, 14};
    MySet<int> unionSet = mySet1.UnionSet(mySet2);
    for (int i = 0; i < unionSet.Length(); ++i) {
        EXPECT_EQ(unionSet[i], unionArrayOfIntegers[i]);
    }
}

TEST(SetTestSuite, IntersectionTest) {
    MySet<int> mySet1;
    mySet1.Add(1);
    mySet1.Add(2);
    mySet1.Add(3);
    mySet1.Add(4);
    mySet1.Add(5);

    MySet<int> mySet2;
    mySet2.Add(10);
    mySet2.Add(11);
    mySet2.Add(12);
    mySet2.Add(13);
    mySet2.Add(14);
    mySet2.Add(5);
    mySet2.Add(3);
    int intersectionArrayOfIntegers[10] = {3, 5};
    MySet<int> intersectionSet = mySet1.Intersection(mySet2);
    for (int i = 0; i < intersectionSet.Length(); ++i) {
        EXPECT_EQ(intersectionSet[i], intersectionArrayOfIntegers[i]);
    }
}

TEST(SetTestSuite, DifferenceTest) {
    MySet<int> mySet1;
    mySet1.Add(1);
    mySet1.Add(2);
    mySet1.Add(3);
    mySet1.Add(4);
    mySet1.Add(5);

    MySet<int> mySet2;
    mySet2.Add(10);
    mySet2.Add(11);
    mySet2.Add(12);
    mySet2.Add(13);
    mySet2.Add(14);
    mySet2.Add(5);
    mySet2.Add(3);
    int differenceArrayOfIntegers[10] = {1, 2, 4};
    MySet<int> differenceSet = mySet1.Difference(mySet2);
    for (int i = 0; i < differenceSet.Length(); ++i) {
        EXPECT_EQ(differenceSet[i], differenceArrayOfIntegers[i]);
    }
}

TEST(SetTestSuite, SymmetricDifferenceTest) {
    MySet<int> mySet1;
    mySet1.Add(1);
    mySet1.Add(2);
    mySet1.Add(3);
    mySet1.Add(4);
    mySet1.Add(5);

    MySet<int> mySet2;
    mySet2.Add(10);
    mySet2.Add(11);
    mySet2.Add(12);
    mySet2.Add(13);
    mySet2.Add(14);
    mySet2.Add(5);
    mySet2.Add(3);
    int symmetricDifferenceArrayOfIntegers[10] = {1, 2, 4, 10, 11, 12, 13, 14};
    MySet<int> symmetricDifferenceSet = mySet1.SymmetricDifference(mySet2);
    for (int i = 0; i < symmetricDifferenceSet.Length(); ++i) {
        EXPECT_EQ(symmetricDifferenceSet[i], symmetricDifferenceArrayOfIntegers[i]);
    }
}