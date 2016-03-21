#include <string>
#include "gtest/gtest.h"
#include "EmptyProject.h"

TEST(EmptyProjectLooseTests, test_construction_with_count)
{
    EmptyProject e(1);
    EXPECT_EQ(1, e.getCount());
}

class TestEmptyProject : public ::testing::Test
{
    protected:

        TestEmptyProject()
        {
            mExamplePtr = new EmptyProject(5);
        }

        virtual ~TestEmptyProject()
        {
            delete mExamplePtr;
            mExamplePtr = NULL;
        }

        EmptyProject* mExamplePtr;
};

TEST_F(TestEmptyProject, test_example)
{
    // in here you can directly use variables from the TestEmptyProject class (i.e. mExamplePtr and maxNrElements)
    EXPECT_TRUE(true);
}
