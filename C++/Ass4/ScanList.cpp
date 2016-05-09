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
	Scan * p = scans;
	while(p != NULL){
		Scan* scanForRemoval = p;
		p = p -> getNext();
		delete scanForRemoval;
	}
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
	Scan * scanForDeletion = NULL, *current = NULL;
    current = scans;
    if (current->getSerialNumber() == serialNumber)
    {
        scanForDeletion = current;
        scans = scanForDeletion->getNext();
        delete scanForDeletion;
        return true;
    }
    while(current != NULL){
        if (current->getSerialNumber() == serialNumber)
        {
            scanForDeletion = current;
            current = scanForDeletion->getNext();
            delete scanForDeletion;
            return true;
        }
        else{
            current = current->getNext();
        }
    }
    return false;
}

int ScanList::getTimesRecycled(int serialNumber)
{
	Scan *scan  = getScanByNr(serialNumber);
	return scan->getTimesRecycled();
}