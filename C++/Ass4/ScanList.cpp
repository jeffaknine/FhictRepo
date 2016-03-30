#include "ScanList.h"
#include "gtest/gtest.h"
#include <stdio.h>
using namespace std;
int number =0;
ScanList::ScanList()
{
	// *scans = new Scan(number);
	// number++;
}

ScanList::~ScanList()
{
	delete scans;
}

void ScanList::AddScan(int serialNumber)
{
	int index =0;
	Scan scan  = scans;
	while(true)
	{
		if (scan!=NULL)
		{
			scan = scan->getNext();
			if (scan->getSerialNumber() == serialNumber)
			{
				scan->timesRecycled ++;
			}
		}
	}
}

Scan* ScanList::getScanByNr(int position)
{
	if (position => 0 && position < )
	{
		
	}
	else
	{
		return null;
	}
}

bool ScanList::removeScan(int serialNumber)
{
	
}

int ScanList::getTimesRecycled()
{
	
}