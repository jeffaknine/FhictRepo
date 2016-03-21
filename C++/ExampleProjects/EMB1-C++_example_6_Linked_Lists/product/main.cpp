/*
 *  main.cpp
 *
 *  Created on: Sep 25, 2013
 *  Author: P. Lambooij
 */

#include <string>
#include <iostream>
using namespace std;

#include "NodeList.h"
#include "Node.h"

int main()
{
  cout << "Illustration Linked List Operations" << endl;

  NodeList * MyNodeList = new NodeList();
  Node * newNode;
  Node * position;

  MyNodeList->show();

  newNode = new Node(10);
  MyNodeList->insertBefore(newNode, NULL);
  MyNodeList->show();

  newNode = new Node(20);
  position = MyNodeList->getNodeByNr(0);
  MyNodeList->insertAfter(newNode, position);
  MyNodeList->show();

  newNode = new Node(30);
  position = MyNodeList->getNodeByNr(1);
  MyNodeList->insertBefore(newNode, position);
  MyNodeList->show();

  newNode = new Node(40);
  position = MyNodeList->getNodeByNr(2);
  MyNodeList->insertAfter(newNode, position);
  MyNodeList->show();

  position = MyNodeList->getNodeByNr(0);
  MyNodeList->removeNode(position);
  MyNodeList->show();

  cout << endl << "deleting NodeList";
  delete MyNodeList;
  cout << endl;
}
