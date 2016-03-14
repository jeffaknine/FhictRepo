#include "gtest/gtest.h"
#include "PiggyBank.h"

#include <stdio.h>
using namespace std;

TEST(TestOwnerName, startOwnerName)
{
    PiggyBank piggyBank;
    EXPECT_EQ(piggyBank.getOwnerName(), "");
}

TEST(TestOwnerName, setOwnerName)
{
    PiggyBank piggyBank;
    const string name = "Dagobert Duck";
    piggyBank.setOwnerName(name);
    EXPECT_EQ(piggyBank.getOwnerName(), name);
}

TEST(TestBalance, startBalance)
{
    PiggyBank piggyBank;
    EXPECT_EQ(piggyBank.getBalance(), 0);
}

TEST(TestBalance, addBalance)
{
    PiggyBank piggyBank;
    piggyBank.depositMoney(15);
    piggyBank.depositMoney(13);
    EXPECT_EQ(piggyBank.getBalance(), 28);
}

TEST(TestIsBroken, breakPiggyBank)
{
    PiggyBank piggyBank;
    piggyBank.smash();
    EXPECT_TRUE(piggyBank.isBroken());
}

TEST(TestIsBroken, checkIsSmashedOnStart)
{
    PiggyBank piggyBank;
    EXPECT_FALSE(piggyBank.isBroken());
}

class PiggyBankTest : public ::testing::Test {
protected:
	PiggyBank piggyBank;
};


TEST_F(PiggyBankTest, AllTestsWithOneInstance)
{
	ASSERT_FALSE(piggyBank.isBroken() );
    piggyBank.smash();
    EXPECT_TRUE(piggyBank.isBroken());
}
