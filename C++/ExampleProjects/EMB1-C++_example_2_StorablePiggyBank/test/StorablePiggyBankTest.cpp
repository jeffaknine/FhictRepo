#include "gtest/gtest.h"
#include "StorablePiggyBank.h"

#include <stdio.h>
using namespace std;

TEST(TestNrOfObjects, InitialNrOfObjectIsZero)
{
	EXPECT_EQ(0, StorablePiggyBank::getNrOfObjects());
}

TEST(TestNrOfObjects, CreationOfStackObject)
{
	StorablePiggyBank bank;
	EXPECT_EQ(1, StorablePiggyBank::getNrOfObjects());
}

TEST(TestNrOfObjects, CreationOfHeapObject)
{
	StorablePiggyBank *bank = new StorablePiggyBank();
	EXPECT_EQ(1, StorablePiggyBank::getNrOfObjects());
	delete bank;
}

TEST(TestNrOfObjects, CountMultipleObjects)
{
	StorablePiggyBank bank1;
	StorablePiggyBank *bank2 = new StorablePiggyBank();
	EXPECT_EQ(2, StorablePiggyBank::getNrOfObjects());
    delete bank2;
}
