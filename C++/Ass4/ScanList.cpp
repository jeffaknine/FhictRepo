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
	Scan* scan  = scans;
	while(true)
	{
		if (scan!=NULL)
		{
			scan = scan->getNext();
			if (scan->getSerialNumber() == serialNumber)
			{
				//scan->timesRecycled ++;
				break;
			}
		}
	}
}

Scan* ScanList::getScanByNr(int position)
{
	if (position < 0 || scans == NULL)
	{
		return NULL;
	}
	Scan * p = scans;
	int i = 0;
	while ((i < position) && (p != NULL))
	{
		i++;
		p = p->getNext();
	}
	return p;
}

bool ScanList::removeScan(int serialNumber)
{
	
}

int ScanList::getTimesRecycled(int serialNumber)
{
	Scan *scan  = scans;
	while(true)
	{
		if (scan!=NULL)
		{
			scan = scan->getNext();
			if (scan->getSerialNumber() == serialNumber)
			{
				return scan->getSerialNumber();
			}
		}
	}
}