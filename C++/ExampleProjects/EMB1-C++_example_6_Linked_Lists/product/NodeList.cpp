#include "NodeList.h"
#include <cstddef> // needed for definition of NULL
#include <iostream>
using namespace std;

NodeList::NodeList(void)
: head(NULL)
{
}

NodeList::~NodeList(void)
{
  Node * p = head;
  while (p != NULL)
  {
      Node * r = p;
      p = p->getNext();
      delete r;
  }
}

void NodeList::show()
{
  Node * node = head;
  cout << endl << "current nodelist: ";
  while (node != NULL)
  {
      cout << node->getValue() << " -> ";
      node = node->getNext();
  }
  cout << "NULL" << endl;
}

Node * NodeList::getFirstNode(void)
{
  return head;
}

Node * NodeList::getNodeByNr(int nr)
{
  if (nr < 0 || head == NULL)
    return NULL;
  Node * p = head;
  int i = 0;
  while ((i < nr) && (p != NULL))
  {
    i++;
    p = p->getNext();
  }
  return p;
}

bool NodeList::insertAfter(Node * newNode, Node * nodeToInsertAfter)
{
  if (newNode == NULL || nodeToInsertAfter == NULL)
    return false;

  // look for nodeToInsertAfter in list
  Node * p = head;
  while (p != nodeToInsertAfter && p != NULL)
    p = p->getNext();
  if (p == NULL)
  {
    // nodeToInsertAfter was not found in linked list
    return false;
  }
  else
  {
    // nodeToInsertAfter was found in linked list, insert newNode
    newNode->setNext(nodeToInsertAfter->getNext());
    nodeToInsertAfter->setNext(newNode);
    return true;
  }
}

bool NodeList::insertBefore(Node * newNode, Node * nodeToInsertBefore)
{
  if (nodeToInsertBefore == head)
  {
      newNode->setNext(head);
      head = newNode;
      return true;
  }

  if (newNode == NULL || nodeToInsertBefore == NULL)
    return false;

  Node * p = head;
  while (p->getNext() != nodeToInsertBefore && p->getNext() != NULL)
    p = p->getNext();

  if (p->getNext() == nodeToInsertBefore)
  {
      // p is now pointing at the node before nodeToInsertBefore
      newNode->setNext(nodeToInsertBefore);
      p->setNext(newNode);
      return true;
  }
  else
  {
      // nodeToInsertBefore was not found in linked list
      return false;
  }
}

bool NodeList::removeNode(Node * nodeToRemove)
{
  if (nodeToRemove == NULL)
    return false;

  if (nodeToRemove == head)
  {
    delete head;
    head = NULL;
    return true;
  }

  Node * p = head;
  while (p->getNext() != nodeToRemove && p != NULL)
  {
    p = p->getNext();
  }
  if (p == NULL)
  {
    // nodeToRemove is not in the list
    return false;
  }
  else
  {
    // p is now pointing at the node before nodeToRemove
    p->setNext(nodeToRemove->getNext());
    // nodeToRemove has been "cut out of the list"
    delete nodeToRemove;
    return true;
  }
}
