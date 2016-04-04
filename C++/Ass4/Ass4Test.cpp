#include "gtest/gtest.h"
#include "Scan.h"
#include "ScanList.h"

#include <stdio.h>
using namespace std;


class Ass4Test : public ::testing::Test {
protected:
	ScanList* scan;
	virtual void SetUp()
	{
		scan = new ScanList();
	}

	virtual void TearDown()
	{
		delete scan; 
	}
};


TEST_F(Ass4Test, Test)
{
	scan->AddScan(1);
	scan->AddScan(2);
	scan->AddScan(3);
	scan->getTimesRecycled(1);
	Scan* plop = scan->getScanByNr(1);
	int v = plop->getSerialNumber();
	EXPECT_EQ(scan->getScanByNr(0)->getSerialNumber(),1);
	EXPECT_TRUE(scan->removeScan(1));
	EXPECT_EQ(scan->getScanByNr(1)->getSerialNumber(),3);
}
