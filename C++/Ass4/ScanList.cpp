#include "ScanList.h"
#include "gtest/gtest.h"
#include <stdio.h>
using namespace std;

ScanList::ScanList()
:scans(NULL)
{
}

ScanList::~ScanList()
{
	delete scans;
}

void ScanList::AddScan(int serialNumber)
{
	Scan *current, *trailCurrent, *newScan;
	bool found;
	newScan = new Scan(serialNumber);
	newScan->setNext(NULL);
	if (scans == NULL)
	{
		scans = newScan;
	}
	else{
		current = scans;
		found = false;
		while(current != NULL && !found){
			if (current->getSerialNumber() >= serialNumber)
			{
				found = true;
			}
			else{
				trailCurrent = current;
				current = current->getNext();
			}
		}
		if (current == scans)
		{
			newScan->setNext(scans);
			scans = newScan;
		}
		else{
			trailCurrent->setNext(newScan);
			newScan->setNext(current);
		}
	}
	
}

Scan* ScanList::getScanByNr(int position)
{
	// if (position < 0 || scans == NULL)
	// {
	// 	return NULL;
	// }
	// Scan * p = scans;
	// int i = 0;
	// while ((i < position) && (p != NULL))
	// {
	// 	i++;
	// 	p = p->getNext();
	// }
	// return p;
	// int count = 0; /* the index of the node we're currently looking at */
	// 	Scan *current = scans;
	// 	while (current != NULL)
	// 	{
	// 	   if (count<= position && count < size(scans))
	// 		  return current;
	// 		  //return current;
	// 	   count++;
	// 	   current = current->getNext();
	// 	}
	//    return NULL;
	int nrOfScans = 0;
	Scan * scanPointer = scans;
	while(scanPointer != NULL && position >= nrOfScans && position >= 0){
		if (nrOfScans == position)
		{
			return scanPointer;
		}
		scanPointer = scanPointer->getNext();
		nrOfScans++;
	}
	return NULL;
}

bool ScanList::removeScan(int serialNumber)
{
	Scan* scan;
	if(scans->getSerialNumber()==serialNumber)
	{
		scan = scans->getNext();
		delete scans;
		scans = scan;
		return true;
	}
	scan = scans;
	while(scan->getNext()->getSerialNumber() !=serialNumber && scan !=NULL )
	{
		scan=scan->getNext();
	}
	if(scan==NULL)
	{
		return false;
	}
	else
	{	
		scan->setNext(scan->getNext());
		delete scan;
		return true;
	}
}

int ScanList::getTimesRecycled(int serialNumber)
{
	Scan *scan  = getScanByNr(serialNumber);
	return scan->getTimesRecycled();
}